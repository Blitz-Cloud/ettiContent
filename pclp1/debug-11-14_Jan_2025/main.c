
```c
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

```

Acest cod C definește o structură pentru a reprezenta un triunghi echilateral, calculează perimetrul și aria acestuia pe baza unei laturi introduse de utilizator și apoi afișează aceste informații. Iată o explicație detaliată:

**1. Include-uri:**

*   `#include <stdio.h>`: Include fișierul antet standard pentru intrare/ieșire, necesar pentru funcțiile `printf` și `scanf`.
*   `#include <math.h>`: Include fișierul antet standard pentru funcții matematice, necesar pentru funcția `sqrt` (radical).

**2. Structura `TriunghiEchilateral`:**

*   ```c
    struct TriunghiEchilateral {
        int lat;
        int perimetru;
        float arie;
    };
    ```
    *   Definește o structură numită `TriunghiEchilateral` care conține următoarele câmpuri:
        *   `int lat`: Lungimea laturii triunghiului (număr întreg).
        *   `int perimetru`: Perimetrul triunghiului (număr întreg).
        *   `float arie`: Aria triunghiului (număr real cu virgulă mobilă).

**3. Funcția `vedere()`:**

*   ```c
    void vedere (struct TriunghiEchilateral tr) {
        printf("Vedere echilateral:\n");
        printf("Lat = %d\n", tr.lat);
        printf("Perimetru = %d\n", tr.perimetru);
        printf("Arie = %f\n", tr.arie);
    }
    ```
    *   Primește ca argument o structură de tip `TriunghiEchilateral` și afișează informațiile despre triunghi (latura, perimetrul și aria).

**4. Funcția `main()`:**

*   ```c
    int main(void) {
        int latura;
        struct TriunghiEchilateral tr;
        scanf("%d", &latura);
        tr.lat = latura;
        tr.perimetru = latura*3;
        tr.arie = (float)latura* sqrt(3)/4.0;
        vedere(tr);
        return 0;
    }
    ```
    *   `int latura;`: Declară o variabilă întreagă `latura` pentru a stoca lungimea laturii triunghiului introdusă de utilizator.
    *   `struct TriunghiEchilateral tr;`: Declară o variabilă `tr` de tipul structurii `TriunghiEchilateral`.
    *   `scanf("%d", &latura);`: Citește lungimea laturii de la utilizator și o stochează în variabila `latura`.
    *   `tr.lat = latura;`: Atribuie valoarea `latura` câmpului `lat` al structurii `tr`.
    *   `tr.perimetru = latura*3;`: Calculează perimetrul triunghiului (latura * 3) și îl stochează în câmpul `perimetru` al structurii `tr`.
    *   `tr.arie = (float)latura* sqrt(3)/4.0;`: Calculează aria triunghiului folosind formula `(latura * sqrt(3)) / 4` și o stochează în câmpul `arie` al structurii `tr`.  Conversia `(float)latura` este importantă pentru a asigura că rezultatul împărțirii este un număr real cu virgulă mobilă.
    *   `vedere(tr);`: Apeleză funcția `vedere()` pentru a afișa informațiile despre triunghi.
    *   `return 0;`: Returnează 0 pentru a indica faptul că programul s-a executat cu succes.

**Ce face programul:**

1.  Solicită utilizatorului să introducă lungimea laturii unui triunghi echilateral.
2.  Calculează perimetrul și aria triunghiului.
3.  Afișează lungimea laturii, perimetrul și aria triunghiului.

**Exemplu de execuție:**

```
5
Vedere echilateral:
Lat = 5
Perimetru = 15
Arie = 2.165064
```

În acest exemplu, utilizatorul a introdus valoarea 5 pentru lungimea laturii. Programul a calculat perimetrul ca 15 și aria ca 2.165064 și a afișat aceste informații.