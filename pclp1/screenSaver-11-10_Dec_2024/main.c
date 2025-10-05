
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

Acest cod C face următorul lucru:

1.  **Include fișierele antet necesare:**
    *   `stdio.h`: Pentru funcții de intrare/ieșire standard, cum ar fi `printf`.
    *   `stdlib.h`: Pentru funcții generale, inclusiv `div`.

2.  **Definește funcția `main`:**
    *   `int main(void)`: Funcția principală a programului, care nu primește argumente.

3.  **Declară variabile:**
    *   `int i`: O variabilă de tip întreg folosită ca contor în buclă.
    *   `div_t x`: O variabilă de tip `div_t`.  `div_t` este un tip de structură definit în `stdlib.h` care este folosit pentru a stoca rezultatul funcției `div`.

4.  **Bucla `for`:**
    *   `for(i=11; i<20; i++)`: O buclă care iterează de la 11 la 19 (inclusiv).

5.  **Funcția `div`:**
    *   `x = div(i, 7)`:  Pentru fiecare valoare a lui `i`, funcția `div(i, 7)` calculează câtul și restul împărțirii lui `i` la 7.  Rezultatul este stocat în variabila `x` de tip `div_t`.

6.  **Afișarea rezultatului:**
    *   `printf("%d : %d,%d\n", i, x.quot, x.rem)`: Afișează valoarea lui `i`, câtul (`x.quot`) și restul (`x.rem`) împărțirii lui `i` la 7, separate prin două puncte și virgulă.  `\n` adaugă un caracter newline la sfârșitul fiecărei linii.

7.  **Return 0:**
    *   `return 0`: Indică faptul că programul s-a executat cu succes.

**Ce face programul în esență:**

Programul calculează și afișează câtul și restul împărțirii fiecărui număr întreg de la 11 la 19 la 7.

**Exemplu de output:**

```
11 : 1,4
12 : 1,5
13 : 1,6
14 : 2,0
15 : 2,1
16 : 2,2
17 : 2,3
18 : 2,4
19 : 2,5
```

Fiecare linie din output reprezintă un număr `i`, urmat de câtul și restul împărțirii lui `i` la 7. De exemplu, pentru `i = 11`, câtul este 1 și restul este 4, deci linia afișată este `11 : 1,4`.