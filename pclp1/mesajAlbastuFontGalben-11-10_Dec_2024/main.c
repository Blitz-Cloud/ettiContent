
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
	printf(BG_YELLOW FG_BLUE"hello\n" BGFG_RESET);
	return 0;
}




```

Acest cod este o colecție de funcții utilitare concepute pentru a lucra cu terminale, în special în medii unde funcțiile standard de intrare/ieșire (I/O) și control al terminalului pot fi limitate sau necesită o gestionare mai fină.  Codul include funcții pentru:

**1. Controlul Terminalului:**

*   **`CLRSCR()`**: Șterge ecranul terminalului folosind comanda `system("clear")`.
*   **`GOTOXY(X, Y)`**: Muta cursorul la coordonatele specificate (X, Y) pe terminal.  Folosește secvențe de escape ANSI pentru a controla poziția cursorului.
*   **`DELLINE(X, Y)`**: Șterge linia de la coordonatele specificate (X, Y).
*   **Definirea culorilor**: Definește coduri ANSI escape pentru culori de fundal și de prim-plan (ex: `FG_RED`, `BG_BLUE`, `BGFG_RESET`).

**2. Gestionarea Input-ului de la Tastatură:**

*   **`myfflush()`**:  O funcție de flush a buffer-ului de intrare standard (stdin).  Folosește `dup`, `tcdrain`, `tcflush` și `close` pentru a asigura că toate datele rămase în buffer-ul stdin sunt eliminate.
*   **`mygetchar()`**:  Citește un caracter de la intrare standard, presupunând că terminalul este în modul "read-by-line" (adică, așteaptă un Enter).  Consumă și caracterul newline (`\n`).
*   **`getch()`**:  Citește un caracter de la tastatură fără a-l afișa pe ecran (fără echo) și fără a aștepta Enter.  Modifică atributele terminalului folosind `termios` pentru a dezactiva modul canon (ICANON) și echo (ECHO).
*   **`getche()`**:  Citește un caracter de la tastatură și îl afișează pe ecran (cu echo), dar fără a aștepta Enter.  Modifică atributele terminalului folosind `termios` pentru a dezactiva modul canon (ICANON).
*   **`getche2()`**: O altă implementare a `getche`, folosind comenzi `stty` pentru a modifica modul terminalului.
*   **`kbhit()`**:  Verifică dacă s-a apăsat o tastă fără a bloca execuția programului.  Folosește `termios` pentru a dezactiva modul canon și echo, și `fcntl` pentru a seta stdin în mod non-blocant.  Returnează 1 dacă o tastă a fost apăsată, 0 altfel.
*   **`kbhit_wait()`**:  Așteaptă până când este apăsată o tastă.  Folosește `getch()` într-o buclă pentru a bloca execuția până când este primită o intrare.

**3. Funcții Utilitare Diverse:**

*   **`delay(long msec)`**:  Introduce o pauză în execuția programului pentru un număr specificat de milisecunde.  Folosește `usleep` pentru întârzieri mai mici de 1 secundă și `nanosleep` pentru întârzieri mai mari sau egale cu 1 secundă.
*   **`rotr(unsigned int nr, unsigned int pos)`**:  Realizează o rotație la dreapta (rotate right) a unui număr întreg fără semn cu un număr specificat de poziții.
*   **`rotl(unsigned int nr, unsigned int pos)`**:  Realizează o rotație la stânga (rotate left) a unui număr întreg fără semn cu un număr specificat de poziții.
*   **`printb(unsigned int nr)`**:  Afișează reprezentarea binară a unui număr întreg fără semn.

**4. `main()` (în exemplele date):**

*   **Exemplul 1:** Afișează cuvântul "Windows" în albastru pe o poziție aleatoare a ecranului, repetând până când este apăsată o tastă.
*   **Exemplul 2:** Demonstrează utilizarea funcțiilor `getch()`, `getche()`, `printb()`, `rotr()`, `rotl()` și `kbhit()`.  Citește caractere cu și fără echo, afișează o parolă mascată, afișează reprezentarea binară a unui număr și așteaptă apăsarea unei taste.
*   **Exemplul 3:** Afișează "hello" cu fundal galben și text albastru.

**Observații Importante:**

*   **Dependențe de Terminal:** Codul este puternic dependent de terminal și de suportul pentru secvențe de escape ANSI.  Este posibil să nu funcționeze corect în toate mediile (de exemplu, în unele IDE-uri sau console care nu suportă ANSI escape codes).
*   **`stty`:** Utilizarea comenzilor `system("/bin/stty ...")` este o abordare mai puțin portabilă și mai puțin sigură decât utilizarea directă a funcțiilor `termios`.  Este recomandat să se evite utilizarea `system()` pe cât posibil.
*   **`myfflush()`**: Implementarea `myfflush()` este complexă și poate fi inutilă.  În multe cazuri, `fflush(stdin)` ar fi suficient (deși comportamentul `fflush(stdin)` este nedefinit în standardul C).
*   **`kbhit()`**:  Implementarea `kbhit()` include o întârziere de 150ms (`delay(150)`), ceea ce poate afecta reactivitatea programului.

În concluzie, acest cod oferă un set de instrumente pentru a controla terminalul și a gestiona intrarea de la tastatură într-un mod mai detaliat decât funcțiile standard C.  Cu toate acestea, este important să se țină cont de dependențele de terminal și de potențialele probleme de portabilitate și securitate.