#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 		80

#define GOTOXY(X, Y)	printf("\x1B[%d;%df" , (Y), (X))
#define CLRSCR()	system("clear")

typedef struct {
	int val;
} info_t;

typedef struct _node {
	info_t data;
	struct _node *link;
} node_t; 

typedef struct {
	node_t *top;
} stack_t;


void Creare(stack_t *s){
	s->top = NULL;
}

int TestVida(stack_t *s){
	return s->top == NULL;
}

void Introducere(stack_t *s, info_t *d){
	node_t *elem;

	if((elem = (node_t *)malloc(sizeof(node_t))) != NULL){
		elem->data = *d;	
		elem->link = s->top;
		s->top = elem;
	} else {
		perror("\nCouldn't malloc enough room !\n");
		exit(EXIT_FAILURE);
	}
}

int Extragere(stack_t *s, info_t *d){
	node_t *temp;

	if(TestVida(s)) return 0;
	else {
		*d=s->top->data;
		temp = s->top->link;
		s->top = temp;
		return 1;
	}
}

int InfoVarf(stack_t *s, info_t *d){
	if(TestVida(s)) return 0;
	else {
		*d = s->top->data;
		return 1;
	}
}

void _write_out(char out[N], int k, int poz){
	int i;

	GOTOXY(1, poz);
	if(k == 0) printf("vida");
	for(i = 0; i < k; i++) printf("%c", out[i]);
}


void PrintStiva(stack_t *s, char o[N], int v, int poz) {
	node_t *elem;	//auxiliar
	
	_write_out(o, v, poz);
	GOTOXY(40, poz);
	elem = s->top;
	if(TestVida(s)) printf("vida");		//de ce nu avem return aici ?
	while(s->top != NULL) {
		printf("%c", s->top->data.val);
		s->top = s->top->link;
	}
	s->top = elem;
}


int main(void){
	int Poz;		//pozitie de afisare
	char InputBuff[N];	//buffer de intrare
	char OutputBuff[N];	//buffer de iesire
	char *term = "#";	//terminator de expresie

	info_t A;	
	info_t B;

	stack_t Stiva;

	char  curr;		//caracter curent
	char i,j;		//indecsi in buff de in, respectiv out
	char k;

	CLRSCR();
	
	printf("Introduceti expresia in forma infixata:");
	scanf("%s", InputBuff);
	//adauga terminatorul
	strcat(InputBuff, term);	

	Creare(&Stiva);		//creare stiva
	
	//algoritmul de conversie a expresiei din forma infixata in forma postfixata
	i = j = 0;
	curr = InputBuff[i++];
	GOTOXY(1, 3);
	printf("Iesire:");

	GOTOXY(40, 3);
	printf("Continutul stivei");
	GOTOXY(1, 5);
	printf("vida");
	GOTOXY(40, 5);
	printf("vida");

	Poz = 6;
	while(curr != '#') {
		//verifica daca current este operand 'a' = 0x61, ..., 'z' = 0x7a;
		if((curr >= 0x61) && (curr <= 0x7a)){	//pot sa lipseasca parantezele din expresia logica ?
			OutputBuff[j++] = curr;
			PrintStiva(&Stiva, OutputBuff, j, Poz);
		} else {
			InfoVarf(&Stiva, &A);

			if(curr == '*'){
				if(A.val == '*'){
					while(!TestVida(&Stiva)){
						if((A.val == '(') || (A.val == '+')) break;
						Extragere(&Stiva, &B);
						OutputBuff[j++] = B.val;
						InfoVarf(&Stiva, &A);
					}
				}
				B.val = curr;
				Introducere(&Stiva, &B);
			}

			if(curr == '+'){
				if((A.val == '*') || (A.val == '+')){
					while(!TestVida(&Stiva)){
						if(A.val == '(') break;
						Extragere(&Stiva, &B);
						OutputBuff[j++] = B.val;
						InfoVarf(&Stiva, &A);
					}
				}
				B.val = curr;
				Introducere(&Stiva, &B);
			}

			if(curr == '('){
				B.val = curr;
				Introducere(&Stiva, &B);	
			}

			if(curr == ')'){
				if((A.val == '*') || (A.val == '+')) {
					while(!TestVida(&Stiva)){
						if(A.val == '(') break;
						Extragere(&Stiva, &B);
						OutputBuff[j++] = B.val;
						InfoVarf(&Stiva, &A);
					}
					Extragere(&Stiva, &B);	//se extrage '('
				}
				PrintStiva(&Stiva, OutputBuff, j, Poz);
			} 
		} //end of else
		//citeste urmatorul caracter
		curr = InputBuff[i++];
		Poz++;
	} //end of while(curr != ...
		
	//descarca stiva
	while(!TestVida(&Stiva)){
		Extragere(&Stiva, &B);
		OutputBuff[j++] = B.val;
	}
	PrintStiva(&Stiva, OutputBuff, j, Poz);

	//scrie expresia in forma postfixata
	printf("\n\nExpresia in forma postfixata: ");
	for(k = 0; k < j; k++) printf("%c", OutputBuff[k]);
	printf("\n");	

	getchar();

	return EXIT_SUCCESS;
}
