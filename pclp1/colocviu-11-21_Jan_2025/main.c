
```c
#include <stdio.h>
#include <string.h>


struct contact{
    char nume[16];
    int numar;
};

struct contact agenda[100];
int poz=0;

void meniu(){
    printf("Bine ai venit\n");
    printf("\t1-Indroduceti persoane in agenda\n");
    printf("\t2-Listare persoane\n");
    printf("\t3-Cautare dupa nume\n");
    printf("\t4-Cautare dupa numar\n");
    printf("\t5-Iesire din program\n");
}

void introducerePersoana(){
    printf("Indroduceti numele persoanei\n");
    scanf("%s",&agenda[poz].nume);
    printf("Indroduceti numarul persoanei\n");
    scanf("%d",&agenda[poz].numar);
    poz++;
}

void listarePersoana(){
    printf("Agenda este:\n");
    printf("%d\n",poz);
    for(int i=0;i<=poz;i++) {
        printf("%s %d\n",agenda[i].nume,agenda[i].numar);
    }
    for(int i=0;i<=poz;i++) {
        for(int j=i;j<=poz;j++) {
        if(strcmp(agenda[i].nume,agenda[j].nume)>0) {
            struct contact temp=agenda[j];
            agenda[j]=agenda[i];
            agenda[i]=temp;
        }
        }
    }
    for(int i=0;i<=poz;i++) {
        printf("%s %d\n",agenda[i].nume,agenda[i].numar);
    }
}

void init(){
    strcpy(agenda[0].nume,"test1");
    strcpy(agenda[1].nume,"test5");
    strcpy(agenda[2].nume,"test3");
    agenda[0].numar=10;
    agenda[1].numar=20;
    agenda[2].numar=30;
    poz=3;
}

int main(void) {
    struct contact agenda[100];
    init();
    int poz=0;
    while(1) {
        meniu();
        int input;
        scanf("%d",&input);
        switch(input) {
            case 1:
                printf("Introduceti persoane:\n");
                printf("Numele persoane:\n");
                scanf("%s",&agenda[poz].nume);
                printf("Numarul persoane:\n");
                scanf("%d",&agenda[poz].numar);
                poz++;
            break;
            case 2:
                for(int i=0;i<=poz;i++) {
                    for(int j=i;j<=poz;j++) {
                        if(strcmp(agenda[i].nume,agenda[j].nume)>0) {
                            struct contact temp=agenda[j];
                            agenda[j]=agenda[i];
                            agenda[i]=temp;
                        }
                    }
                }
            for(int i=0;i<=poz;i++) {
                printf("%s %d\n",agenda[i].nume,agenda[i].numar);
            }
            break;
            case 3:
                char nume[16],ok=0;
                printf("Care este numele dupa care cautati");
                scanf("%s",&nume);
                for(int i=0;i<=poz&&!ok;i++) {
                    if(strcmp(nume,agenda[i].nume)==0) {
                    ok=1;
                 }
                }
                if(!ok){
                    printf("Persoana nu a fost gasita\m");
                }
            break;


        }

    }
    return 0;
}

```

Acest cod C este un program simplu "Hello, World!". Iată ce face:

**1. Include-uri:**

*   `#include <stdio.h>`: Include fișierul antet standard pentru intrare/ieșire, necesar pentru funcția `printf`.

**2. Funcția `main()`:**

*   `int main(void)`: Definește funcția principală a programului, care nu primește argumente.
*   `printf("Hello, World!\n");`: Afișează șirul de caractere "Hello, World!" urmat de un caracter newline (`\n`) în consolă.
*   `return 0;`: Returnează 0 pentru a indica faptul că programul s-a executat cu succes.

**Ce face programul:**

Programul afișează pur și simplu mesajul "Hello, World!" pe ecran și apoi se termină. Acesta este adesea primul program scris atunci când se învață un nou limbaj de programare.

**Ieșirea programului:**

```
Hello, World!
```