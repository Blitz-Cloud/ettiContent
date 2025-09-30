#include <stdio.h>
#include <stdbool.h>
#include <string.h>
// 0123
// [a,b,c,d]
// contor

// verificare spatiu pe baza contorului
// dupa fac crearea

struct gamer {
    char alias[9];
    char name[9];
    int age;
    int score;
} gameri[4];

int contor = 0;


void Show_gamers() {
    printf("Gameri:");
    for (int i = 0; i < contor; i++) {
        printf(" %s ", gameri[i].alias);
    }
    printf("\n");
};

void add_new_gamer() {
    struct gamer player4;
    printf("Please enter your name: ");
    scanf("%s", &player4.name);
    printf("Please enter your alias: ");
    scanf("%s", &player4.alias);
    printf("Please enter your age: ");
    scanf("%d", &player4.age);
    printf("Your score is 0");
    player4.score = 0;
};

int main() {
    gameri[0].age = 18;
    gameri[0].score = 49;
    strcpy(gameri[0].name, "Mihai");
    strcpy(gameri[0].alias, "Mishu");

    gameri[1].age = 22;
    gameri[1].score = 166;
    strcpy(gameri[1].name, "Stefan");
    strcpy(gameri[1].alias, "Fane");

    gameri[2].age = 19;
    gameri[2].score = 80;
    strcpy(gameri[2].name, "Dumitru");
    strcpy(gameri[2].alias, "Mitrus");
    contor = contor + 3;


    while (1) {
        //meniu
        printf("MENIU \n|0- listeaza toate aliasurile.(in ordinea introdusa.\n|1- introduce gamer;\n|2- afiseaza scorul pt un alias dat.\n|3- afiseaza clasamentul\n|4- afiseaza lista de aliasuri, cu varsta mai mare decat o val data.\n|5- sterge gamer din clasament.\n|6- iesire din program\n");

        int input;
        printf("Please enter your input: ");
        printf("%c",input);
        scanf("%d", &input);

        switch (input) {

            case 0:
                Show_gamers();
            break;
            case 1:
                if (contor <= 4) {
                    contor++;
                    add_new_gamer();
                } else printf("Nu mai se pot adauga playeri");
            break;
            case 2:
                char h[9];
            printf("Whose score do you want to know?");
            scanf("%s", &h);
            for (int i = 0; i < contor; i++)
                if (strcmp(gameri[i].alias, h) == 0)
                    printf("Scorul playerului %s este %d \n", gameri[i].name,
                           gameri[i].score);
            break;
            case 3:
                struct gamer *deSortat[3];
            for (int i = 0; i < contor; i++) {
                deSortat[i] = &gameri[i];
            }
            for (int i = 0; i < contor; i++) {
                for (int j = i; j < contor; j++) {
                    if (deSortat[i]->score > deSortat[j]->score) {
                        struct gamer *aux = deSortat[i];
                        deSortat[i] = deSortat[j];
                        deSortat[j] = aux;
                    }
                }
            }
            for (int i = 0; i < contor; i++) {
                printf("%s %d ", deSortat[i]->alias, deSortat[i]->score);
            }
            break;

            case 4:
                int varsta;
            printf("Introduceti varsta minima pentru jucatori: ");
            scanf("%d", &varsta);
            printf("Cei care au mai mult de %d ani, sunt:");
            for (int i = 0; i < contor; i++) {
                if (gameri[i].age >= varsta) { printf("%s ", gameri[i].alias); }
            }
            break;
            case 5:
                char uti[9];
            printf("Ce utlizator doriti sa stergeti?");
            scanf("%s", &uti);
            for (int i = 0; i < contor; i++) {
                if (strcmp(gameri[i].alias, uti) == 0 || strcmp(gameri[i].name, uti) == 0) {
                    break;
                }
            }
            int i;
            if (i != contor-1) {
                for (int i ; i < contor - 1; i++) {
                    gameri[i] = gameri[i + 1];
                }
            }
            contor--;
            for (int i = 0; i < contor; i++) {
                printf("%s ", gameri[i].alias);
            }

            break;
            case 6:
                printf("Ati iesit din program cu succes!");
                return 0;
            break;

        }

    }
}


`