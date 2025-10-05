
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
	CLRSCR();
	while(!kbhit()) {
		srand(time(NULL));
		int nr = rand()%20;
		GOTOXY(nr,nr);
		printf(FG_BLUE"Windows"BGFG_RESET);
		delay(200);
		CLRSCR();

	}
	return 0;
}




```

Acest cod C implementează o serie de funcții utilitare care sunt comune în programarea de consolă, dar nu sunt standard în toate mediile. Scopul principal pare a fi acela de a oferi funcționalități similare cu cele găsite în mediile DOS/Turbo C, cum ar fi `getch()`, `getche()`, `kbhit()`, `GOTOXY()`, `CLRSCR()`, etc., dar pentru un sistem Unix-like (presupunem Linux, având în vedere utilizarea `system("clear")` și `/bin/stty`).

**Funcțiile implementate și ce fac ele:**

*   **`delay(long msec)`:**  Implementează o funcție de întârziere (pauză) pentru un număr specificat de milisecunde. Folosește `usleep()` pentru întârzieri mai mici de 1 secundă și `nanosleep()` pentru întârzieri mai mari, gestionând și întreruperile (semnalul `EINTR`).
*   **`getch(void)`:**  Citește un caracter de la tastatură fără a-l afișa pe ecran (fără ecou) și fără a aștepta apăsarea tastei Enter.  Modifică atributele terminalului folosind `termios` pentru a dezactiva modul canonic (line buffering) și ecoul.
*   **`getche(void)`:**  Citește un caracter de la tastatură și îl afișează pe ecran (cu ecou) fără a aștepta apăsarea tastei Enter.  Similar cu `getch()`, dar lasă ecoul activat.
*   **`getche2(void)`:** O altă implementare a `getche`, folosind comenzi `stty` pentru a modifica comportamentul terminalului.  Această abordare este mai puțin portabilă și mai puțin recomandată decât utilizarea `termios`.
*   **`kbhit(void)`:**  Verifică dacă a fost apăsată o tastă fără a bloca execuția programului.  Modifică atributele terminalului pentru a dezactiva modul canonic și ecoul, și setează terminalul în mod non-blocant folosind `fcntl`.  Dacă un caracter este disponibil, îl pune înapoi în bufferul de intrare cu `ungetc()`.
*   **`kbhit_wait(void)`:**  Așteaptă până când este apăsată o tastă.  Folosește `system("/bin/stty raw")` pentru a dezactiva buffering-ul și apoi apelează `getch()` într-o buclă.
*   **`GOTOXY(X, Y)`:**  Mută cursorul la coordonatele specificate (X, Y) pe ecran.  Folosește secvențe de control ANSI escape pentru a realiza acest lucru.
*   **`CLRSCR()`:**  Șterge ecranul consolei.  Folosește comanda `system("clear")`, care este specifică sistemelor Unix-like.
*   **`rotr(unsigned int nr, unsigned int pos)`:**  Realizează o rotație la dreapta a unui număr întreg fără semn cu un număr specificat de poziții.
*   **`rotl(unsigned int nr, unsigned int pos)`:**  Realizează o rotație la stânga a unui număr întreg fără semn cu un număr specificat de poziții.
*   **`printb(unsigned int nr)`:**  Afișează reprezentarea binară a unui număr întreg fără semn.
*   **`myfflush(void)`:**  Încearcă să golească bufferul de intrare standard.  Folosește `tcdrain` și `tcflush` pentru a asigura că toate datele sunt trimise și bufferul este golit.
*   **`mygetchar(void)`:**  Citește un caracter de la intrarea standard.

**Definiri de macro-uri:**

*   **`FG_BLACK`, `FG_RED`, ..., `FG_WHITE`:**  Definesc secvențe de control ANSI escape pentru a seta culoarea textului (foreground).
*   **`BG_BLACK`, `BG_RED`, ..., `BG_WHITE`:**  Definesc secvențe de control ANSI escape pentru a seta culoarea de fundal (background).
*   **`BGFG_RESET`:**  Definește secvența de control ANSI escape pentru a reseta culorile la valorile implicite.
*   **`DELLINE(X, Y)`:**  Șterge o linie de la coordonatele specificate.

**Exemplu de utilizare (funcția `main()`):**

Funcția `main()` demonstrează utilizarea funcțiilor definite:

1.  Șterge ecranul (`CLRSCR()`).
2.  Intră într-o buclă `while` care rulează până când este apăsată o tastă (`!kbhit()`).
3.  În interiorul buclei:
    *   Generează un număr aleatoriu.
    *   Mută cursorul la o poziție aleatoare pe ecran (`GOTOXY()`).
    *   Afișează textul "Windows" cu culoarea albastră (`FG_BLUE`) și resetează culorile (`BGFG_RESET`).
    *   Așteaptă 200 de milisecunde (`delay()`).
    *   Șterge ecranul (`CLRSCR()`).

**Observații importante:**

*   **Portabilitate:** Codul este dependent de sistemul de operare.  Utilizarea `system("clear")` și `system("/bin/stty ...")` îl face specific sistemelor Unix-like.  Pentru a-l face mai portabil, ar trebui să se folosească alternative standard POSIX sau să se includă cod condițional pentru diferite sisteme de operare.
*   **Terminal real vs. Consolă:** Comentariul indică faptul că funcțiile au fost testate doar pe terminale reale, nu pe console.  Acest lucru sugerează că ar putea exista probleme cu emulatoarele de terminal sau cu consolele virtuale.
*   **Codare ASCII:**  Codul menționează suport doar pentru codarea ASCII.  Acest lucru înseamnă că caracterele non-ASCII (cum ar fi cele din UTF-8) ar putea fi afișate incorect.
*   **Securitate:** Utilizarea `system()` poate fi riscantă dacă intrarea nu este controlată cu atenție, deoarece permite execuția de comenzi shell arbitrare.  În acest caz, utilizarea `system("clear")` și `system("/bin/stty ...")` este relativ sigură, dar ar trebui evitată în general.
*   **`termios`:** Utilizarea corectă a `termios` este crucială pentru a manipula atributele terminalului.  Este important să se salveze atributele originale și să se restaureze după utilizare pentru a evita efecte secundare nedorite.
*   **`ungetc()`:**  Funcția `ungetc()` pune un caracter înapoi în bufferul de intrare.  Trebuie utilizată cu precauție, deoarece are o capacitate limitată (de obicei, doar un singur caracter).

În concluzie, acest cod oferă o colecție de funcții utilitare pentru programarea de consolă, cu accent pe emularea funcționalităților DOS/Turbo C pe un sistem Unix-like.  Deși funcțional, ar putea beneficia de îmbunătățiri în ceea ce privește portabilitatea, securitatea și gestionarea erorilor.