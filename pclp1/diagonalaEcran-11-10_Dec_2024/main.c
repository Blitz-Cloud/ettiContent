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



