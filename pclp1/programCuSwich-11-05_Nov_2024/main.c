
```c

#include <ctype.h>
#include <stdio.h>

int main(void) {
    printf("\tF file  E edit  C compile  R run  Q quit\n");
    printf("Introduceti o optiune:\n");
    char optiune;
    optiune = getchar();
    getchar();
    optiune = tolower(optiune);

    while(optiune) {
        switch (optiune) {
            case 'f':
                printf("File\n");
                break;
            case 'e':
                printf("Edit\n");
                break;
            case 'c':
                printf("Compile\n");
                break;
            case 'r':
                printf("Run\n");
                break;
            case 'q':
                printf("Quit\n");
                return 0;
                break;
        }
        printf("Introduceti o optiune:\n");
        optiune = getchar();
        getchar();
        optiune = tolower(optiune);
    }
    return 0;
}

```

Acest cod C afișează două linii de numere întregi, prima linie conținând numerele impare de la 0 la 15, iar a doua linie conținând numerele pare de la 0 la 15. Iată o explicație detaliată:

**1. Include-uri:**

*   `#include <stdio.h>`: Include fișierul antet standard pentru intrare/ieșire, necesar pentru funcția `printf`.

**2. Funcția `main()`:**

*   `int main(void)`: Definește funcția principală a programului, care nu primește argumente.
*   `int i=0;`: Declară o variabilă întreagă `i` și o inițializează cu valoarea 0. Această variabilă va fi folosită ca contor în bucle.
*   `for(;i<=15;i++) { i%2==1?printf("%5.2d ",i): 0 ; }`: Această buclă `for` afișează numerele impare de la 0 la 15.
    *   `;`: Clauza de inițializare a buclei `for` este goală, deoarece `i` a fost deja inițializat înainte de buclă.
    *   `i<=15;`: Condiția de continuare a buclei. Bucla va continua să ruleze atâta timp cât `i` este mai mic sau egal cu 15.
    *   `i++`: Incrementează valoarea lui `i` cu 1 după fiecare iterație a buclei.
    *   `i%2==1?printf("%5.2d ",i): 0 ;`: Aceasta este o expresie condițională (operatorul ternar).
        *   `i%2==1`: Verifică dacă `i` este impar (dacă restul împărțirii lui `i` la 2 este 1).
        *   `printf("%5.2d ",i)`: Dacă `i` este impar, afișează valoarea lui `i` cu o lățime de 5 caractere și cu 2 cifre după virgulă (deși nu există virgulă, se vor adăuga zerouri). `%5.2d` este un specificator de format care aliniază numerele la dreapta într-un câmp de 5 caractere și afișează cel puțin două cifre (completând cu zerouri la stânga dacă este necesar).
        *   `0`: Dacă `i` este par, nu face nimic (afișează 0, dar rezultatul nu este folosit).
*   `printf("\n");`: Afișează un caracter newline pentru a trece la linia următoare.
*   `for(i=0;i<=15;i++) { i%2==0?printf("%5.2d ",i): 0; }`: Această buclă `for` afișează numerele pare de la 0 la 15.
    *   `i=0;`: Inițializează variabila `i` cu valoarea 0.
    *   `i<=15;`: Condiția de continuare a buclei. Bucla va continua să ruleze atâta timp cât `i` este mai mic sau egal cu 15.
    *   `i++`: Incrementează valoarea lui `i` cu 1 după fiecare iterație a buclei.
    *   `i%2==0?printf("%5.2d ",i): 0;`: Aceasta este o expresie condițională (operatorul ternar).
        *   `i%2==0`: Verifică dacă `i` este par (dacă restul împărțirii lui `i` la 2 este 0).
        *   `printf("%5.2d ",i)`: Dacă `i` este par, afișează valoarea lui `i` cu o lățime de 5 caractere și cu 2 cifre după virgulă (deși nu există virgulă, se vor adăuga zerouri).
        *   `0`: Dacă `i` este impar, nu face nimic (afișează 0, dar rezultatul nu este folosit).
*   `return 0;`: Returnează 0 pentru a indica faptul că programul s-a executat cu succes.

**Ce face programul:**

Programul afișează două linii de numere întregi. Prima linie conține numerele impare de la 0 la 15, iar a doua linie conține numerele pare de la 0 la 15. Numerele sunt aliniate la dreapta într-un câmp de 5 caractere și sunt afișate cu cel puțin două cifre (completând cu zerouri la stânga dacă este necesar).

**Ieșirea programului:**

```
 01  03  05  07  09  11  13  15 
 00  02  04  06  08  10  12  14 
```