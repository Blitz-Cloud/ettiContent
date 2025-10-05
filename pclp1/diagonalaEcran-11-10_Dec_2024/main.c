
```c
/*
 *  Description	: implementation of delay(), getch(), getche(), kbhit(), kbhit_wait(),
 *  		  GOTOXY(), CLRSCR(), rotr(), ...
 *  		  All functions tested successfully only on real terminals(NOT console).
 *		  Only ASCII encoding support.
 *  Date	: 23/10/2023
 *  Author	: rlupu, dg @ UPB
 */
#include <time.h>
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define CLRSCR()	system("clear");

#define FG_BLACK	"\x1B[30m"
#define FG_RED		"\x1B[31m"
#define FG_GREEN	"\x1B[32m"
#define FG_YELLOW	"\x1B[33m"
#define FG_BLUE		"\x1B[34m"
#define FG_MAGENTA	"\x1B[35m"
#define FG_CYAN		"\x1B[36m"
#define FG_WHITE	"\x1B[37m"

#define BG_BLACK	"\x1B[40m"
#define BG_RED		"\x1B[41m"
#define BG_GREEN	"\x1B[42m"
#define BG_YELLOW	"\x1B[43m"
#define BG_BLUE		"\x1B[44m"
#define BG_MAGENTA	"\x1B[45m"
#define BG_CYAN		"\x1B[46m"
#define BG_WHITE	"\x1B[47m"

#define BGFG_RESET	"\x1B[0m"

#define GOTOXY(X, Y)	printf("\x1B[%d;%df", (Y), (X))
#define DELLINE(X, Y)	do{GOTOXY((X), (Y)); printf("\33[2K\r"); }while(0);


void myfflush(void){
	int stdin2 = dup(STDIN_FILENO);

	tcdrain(stdin2);
	tcflush(stdin2, TCIFLUSH);
	close(stdin2);
}

int mygetchar(void){	//each char read terminated by <CR>, with echo; assumed read-by-line terminal mode
	char ch;

	myfflush();
	//while((ch = (char)getchar()) == '\n');
	ch = (char)getchar();
	(void)getchar();

	myfflush();

	return ch;
}


int getch(void){
	int ch;
	struct termios oldattr, newattr;

	tcgetattr(STDIN_FILENO, &oldattr);
	memcpy(&newattr, &oldattr, sizeof(struct termios));
	newattr.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newattr);

	ch = getc(stdin);

	tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);

	return ch;
}

int getche(void){
	int ch;
	struct termios oldattr, newattr;

	tcgetattr(STDIN_FILENO, &oldattr);
	memcpy(&newattr, &oldattr, sizeof(struct termios));
	newattr.c_lflag &= ~(ICANON);
	tcsetattr(STDIN_FILENO, TCSANOW, &newattr);

	ch = getc(stdin);

	tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);

	return ch;
}

int getche2(void){	//each char read w/o <CR>, with echo
	char ch;

	system("/bin/stty raw");	//disable <CR>
	//myfflush();

	ch = getchar();
	system("/bin/stty cooked");

	return ch;
}

int delay(long msec)
{
	int res;
	struct timespec ts;

	if(msec < 1000){
		res = usleep(msec * 1000);
		return res;
	}

	ts.tv_sec  = msec / 1000;
	ts.tv_nsec = (msec % 1000) / 1000000;

	do
	{
		res = nanosleep(&ts, NULL);
	} while(res && errno == EINTR);

	return res;
}

int kbhit(void){	//non-blocking version
	struct termios oldt, newt;
	int ch;
	int oldf;

	tcgetattr(STDIN_FILENO, &oldt);
	memcpy(&newt, &oldt, sizeof(struct termios));
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

	ch = getc(stdin);
	delay(150);

	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	fcntl(STDIN_FILENO, F_SETFL, oldf);

	if(ch != EOF){
		ungetc(ch, stdin);
		return 1;
	}

	return 0;
}

int kbhit_wait(void){			//blocking version, until any key is pressed
	system("/bin/stty raw");	//disable <CR>

	myfflush();
	while(getch() == -1);

	system("/bin/stty cooked");

	return 1;
}

unsigned int rotr(unsigned int nr, unsigned int pos){
	return (nr >> pos) | (nr << (sizeof(unsigned int)*8 - pos));
}

unsigned int rotl(unsigned int nr, unsigned int pos){
	return (nr << pos) | (nr >> (sizeof(unsigned int)*8 - pos));
}

void printb(unsigned int nr){
	unsigned int mask = 0x00000001, i;
	char binary[128];

	printf("Binary representation of integer %d is:\n", nr);
	printf("MSb\t\t\t\t\t\t\t\tLSb\n  ");

	for(i = 0; i < sizeof(unsigned int)*8; i++, mask = mask << 1){
		binary[i] = (nr & mask) ? '1' : '0';
	}

	for(i = sizeof(unsigned int)*8; i > 0; i--){
		printf("%c", binary[i-1]);
		if( i && ((i-1) % (sizeof(unsigned int)*8) ) && !((i-1) % 8) )
			printf(".");
		else
			printf(" ");
	}

	printf("\n");
}


int main(){
	char c, passwd[4];
	int i;
	//unsigned int nr = 1073741824;
	//int nr = -2147483648;
	int nr = 0xaaaa0000;


	CLRSCR();
	delay(1000);
	srand(time(NULL));

	printf(FG_GREEN"Am generat = %d\n"BGFG_RESET, rand());
	GOTOXY(1,5);
	printf(BG_YELLOW FG_RED"hello\n" BGFG_RESET);
	printf(FG_BLUE"hello\n " BGFG_RESET);

	printf("Read a char w/o echo: ");
	c = getch();
	printf("\nCharacter is: %c\n", c);

	printf("Read a char w/ echo: ");
	c = getche();
	printf("\nCharacter is: %c\n", c);

	printf("Enter the password: ");
	for(i = 0; i < 4; i++){
		passwd[i] = getch(); putchar('*');
		//passwd[i] = mygetchar();
		//passwd[i] = getche();
	}
	passwd[i] = '\0';
	printf("\npassword is: %s\n", passwd);

	printb(nr);
	printb(rotr(nr, 16));
	printb(rotl(rotr(nr, 16), 16));

	GOTOXY(15,20);
	printf("Press any key!");
	myfflush();
	while(!kbhit());
	//kbhit_wait();

	return 0;
}




```

Acest cod este o colecție de funcții utilitare pentru lucrul cu terminalul în C, împreună cu un program `main` care demonstrează utilizarea lor.  Scopul principal este de a oferi funcționalități similare cu cele găsite în biblioteci grafice simple (cum ar fi `conio.h` din Borland C++), dar care funcționează direct cu terminalul, fără a folosi o interfață grafică.

**Structura generală:**

1.  **Antet (Comentarii):** Descrie scopul codului, autorul și data.  Subliniază că funcțiile au fost testate pe terminale reale, nu pe console (ceea ce sugerează că ar putea avea probleme cu emulatoare de terminal mai simple).

2.  **Include-uri:** Include fișierele antet standard necesare pentru funcțiile utilizate:
    *   `<time.h>`: Pentru funcții legate de timp (e.g., `delay`, `srand`, `time`).
    *   `<termios.h>`: Pentru controlul terminalului (e.g., dezactivarea ecoului, citirea caracterelor fără Enter).
    *   `<fcntl.h>`: Pentru controlul fișierelor (e.g., setarea modului non-blocant pentru `kbhit`).
    *   `<unistd.h>`: Pentru funcții POSIX (e.g., `usleep`, `system`, `dup`, `close`).
    *   `<stdio.h>`: Pentru intrare/ieșire standard (e.g., `printf`, `getchar`, `getc`).
    *   `<stdlib.h>`: Pentru funcții generale (e.g., `system`, `rand`, `srand`).
    *   `<string.h>`: Pentru funcții de manipulare a șirurilor (e.g., `memcpy`).
    *   `<errno.h>`: Pentru gestionarea erorilor.

3.  **Definiri de Macro-uri (`#define`):**
    *   `CLRSCR()`: Șterge ecranul terminalului folosind comanda `clear`.
    *   `FG_BLACK`, `FG_RED`, ..., `FG_WHITE`: Definiri pentru culorile textului (foreground) folosind coduri escape ANSI.
    *   `BG_BLACK`, `BG_RED`, ..., `BG_WHITE`: Definiri pentru culorile de fundal (background) folosind coduri escape ANSI.
    *   `BGFG_RESET`: Resetează culorile la valorile implicite.
    *   `GOTOXY(X, Y)`: Muta cursorul la coordonatele (X, Y) în terminal folosind coduri escape ANSI.  Reține că Y este prima coordonată în codul escape.
    *   `DELLINE(X, Y)`: Șterge linia de la coordonatele (X, Y).

4.  **Funcții:**

    *   `myfflush()`:  O implementare personalizată a `fflush(stdin)`.  Folosește `dup`, `tcdrain`, `tcflush` și `close` pentru a asigura că bufferul de intrare este golit.  Este important de reținut că `fflush(stdin)` are un comportament nedefinit în standardul C, deci această implementare încearcă să ofere o alternativă mai sigură.

    *   `mygetchar()`: Citește un caracter de la intrare, presupunând că terminalul este în modul "read-by-line".  Consumă caracterul newline (`\n`) după citirea caracterului dorit.

    *   `getch()`: Citește un caracter fără ecou și fără a necesita apăsarea tastei Enter.  Modifică atributele terminalului folosind `termios` pentru a dezactiva `ICANON` (modul canonic, care necesită Enter) și `ECHO` (ecoul caracterelor).

    *   `getche()`: Citește un caracter cu ecou, dar fără a necesita apăsarea tastei Enter.  Similar cu `getch`, dar dezactivează doar `ICANON`.

    *   `getche2()`: O altă variantă de `getche`, care folosește comenzi `system` pentru a schimba modul terminalului.  Această abordare este mai puțin portabilă și mai puțin eficientă decât utilizarea `termios`.

    *   `delay(long msec)`: Introduce o pauză de `msec` milisecunde.  Folosește `usleep` pentru întârzieri mai mici de 1 secundă și `nanosleep` pentru întârzieri mai mari.  Bucla `do...while` cu verificarea `errno == EINTR` este importantă pentru a gestiona situația în care semnalele întrerup funcția `nanosleep`.

    *   `kbhit()`: Verifică dacă a fost apăsată o tastă fără a bloca execuția.  Modifică atributele terminalului pentru a dezactiva modul canonic și ecoul, și setează modul non-blocant pentru intrare.  Citește un caracter cu `getc`. Dacă s-a citit un caracter (diferit de `EOF`), îl pune înapoi în bufferul de intrare cu `ungetc` și returnează 1.  Altfel, returnează 0.  Include o mică întârziere de 150ms.

    *   `kbhit_wait()`: Așteaptă până când este apăsată o tastă.  Folosește comenzi `system` pentru a schimba modul terminalului.  Această abordare este mai puțin portabilă și mai puțin eficientă decât utilizarea `termios`.

    *   `rotr(unsigned int nr, unsigned int pos)`: Rotește un număr întreg fără semn `nr` la dreapta cu `pos` biți.

    *   `rotl(unsigned int nr, unsigned int pos)`: Rotește un număr întreg fără semn `nr` la stânga cu `pos` biți.

    *   `printb(unsigned int nr)`: Afișează reprezentarea binară a unui număr întreg fără semn.

5.  **Funcția `main()`:**

    *   Demonstrează utilizarea funcțiilor definite anterior.
    *   Șterge ecranul.
    *   Inițializează generatorul de numere aleatoare.
    *   Afișează mesaje colorate folosind codurile escape ANSI.
    *   Citește caractere cu și fără ecou folosind `getch` și `getche`.
    *   Citește o parolă, ascunzând caracterele introduse cu asteriscuri.
    *   Afișează reprezentarea binară a unui număr și a rotațiilor sale.
    *   Așteaptă apăsarea unei taste folosind `kbhit` și `kbhit_wait`.
    *   Înainte de a astepta apasarea unei taste, afiseaza un text la coordonatele (15,20)

**În rezumat, codul oferă un set de funcții pentru a controla terminalul, a citi caractere de la tastatură (cu sau fără ecou, cu sau fără Enter), a introduce întârzieri, a detecta apăsări de taste și a manipula biți. Funcția `main` demonstrează utilizarea acestor funcții.**

**Puncte de îmbunătățire:**

*   **Portabilitate:** Utilizarea `system("/bin/stty ...")` face codul mai puțin portabil, deoarece depinde de existența comenzii `stty` și de locația ei.  Ar fi mai bine să se folosească doar `termios` pentru controlul terminalului.
*   **Gestionarea erorilor:**  Ar trebui adăugată o gestionare mai robustă a erorilor (e.g., verificarea valorilor returnate de `tcgetattr`, `tcsetattr`, `fcntl`, `nanosleep`).
*   **Securitate:**  Citirea parolei ar putea fi îmbunătățită pentru a evita scurgeri de informații în cazul în care programul este întrerupt brusc.
*   **Claritate:**  Comentariile ar putea fi mai detaliate în unele locuri.
*   **Consistență:**  Ar trebui aleasă o singură metodă pentru a goli bufferul de intrare (fie `myfflush`, fie o altă abordare).
*   **`kbhit` delay:**  Întârzierea de 150ms din `kbhit` poate face ca detectarea apăsărilor de taste să fie mai lentă decât ar trebui.  Această întârziere ar trebui eliminată sau redusă.

Deși codul funcționează, este important de reținut că manipularea directă a terminalului poate fi complexă și că există biblioteci mai moderne și mai portabile (cum ar fi `ncurses`) care oferă funcționalități similare.