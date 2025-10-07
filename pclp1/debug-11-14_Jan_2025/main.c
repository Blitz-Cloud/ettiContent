#include <stdio.h>

struct {
    char alias[8],nume[8];
    int varsta,scor;
} jucator[4];
void meniu() {
    printf("0-listeaza jucatori\n");
    printf("1-introduce jucatori\n");
    printf("2-afisare scor\n");
    printf("3-afisare clasament\n");
    printf("4-liste de aliasuri dupa varsta\n");
    printf("5-sterge gamer\n");
    printf("6-iesire program\n");
}
int r=-1;
int nr=0;
void listare() {
    for(int i=0;i<=nr;i++)
        printf("%s ",jucator[i].alias);
}
void introducere()
{

    scanf(" %s  %s %d  %d",&jucator[nr].alias,&jucator[nr].nume,&jucator[nr].varsta,&jucator[nr].scor);
    scanf("");
    nr++;
}
void afisarescor() {
    char a[8];
    printf(" Pentru ce alias vrei scorul?:");
    scanf("%s",&a);
    for(int i=0;i<nr;i++)
        if(*jucator[i].alias==*a)
            printf("%d ",jucator[i].scor);
}
void colocviu() {

    do {
        meniu();
        scanf("%d",&r);
        scanf("");
        switch(r) {
            case 0: listare();break;
            case 1: introducere();break;
            case 2: afisarescor();break;
            //case 3: aliascopii();break;

        }

    } while(r!=6);
}
int main(void)
{
    colocviu();
    return 0;
}
