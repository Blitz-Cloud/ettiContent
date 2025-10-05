
```c
#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int i;
    div_t x;
    for(i=11;i<20;i++) {
        x = div(i,7);
        printf("%d : %d,%d\n",i,x.quot,x.rem);
    }
    return 0;
}

```

Acest cod C calculează și afișează valorile sinus pentru o serie de unghiuri exprimate în grade. Iată o explicație detaliată:

**1. Include-uri:**

*   `#include <stdio.h>`: Include fișierul antet standard pentru intrare/ieșire, necesar pentru funcția `printf()`.
*   `#include <math.h>`: Include fișierul antet standard pentru funcții matematice, inclusiv `sin()` și definirea constantei `M_PI`.

**2. Funcția `main()`:**

*   `int main(void)`: Definește funcția principală a programului, care nu primește argumente.
*   `int i;`: Declară o variabilă întreagă `i` pentru a fi folosită ca contor în buclă.
*   `float x[5]={0.0,30.0,45.0,60.0,90.0};`: Declară și inițializează un tablou de tip `float` numit `x` cu 5 elemente. Aceste elemente reprezintă unghiuri în grade: 0, 30, 45, 60 și 90.
*   `printf("%3c",'|');`: Afișează caracterul '|' (bară verticală) cu o lățime de 3 caractere.
*   `printf("%4c",' ');`: Afișează un spațiu cu o lățime de 4 caractere.
*   `printf("%3c",'|');`: Afișează caracterul '|' cu o lățime de 3 caractere.
*   `for(i=0;i<5;i++) { ... }`: Inițializează o buclă `for` care iterează de la `i = 0` până la `i = 4` (inclusiv).
    *   `printf("%4d ",x[i]);`: Afișează valoarea unghiului `x[i]` ca un număr întreg cu o lățime de 4 caractere, urmat de un spațiu.  Deși `x[i]` este `float`, `%4d` îl va converti la `int` pentru afișare.
    *   `printf("%3c",'|');`: Afișează caracterul '|' cu o lățime de 3 caractere.
*   `for(i=0;i<5;i++) { ... }`: Inițializează o a doua buclă `for` care iterează de la `i = 0` până la `i = 4` (inclusiv).
    *   `printf("%4.3f ", sin(x[i]*M_PI/180.0));`: Afișează valoarea sinusului unghiului `x[i]`.
        *   `x[i]*M_PI/180.0`: Convertăște unghiul din grade în radiani.  `M_PI` este o constantă definită în `math.h` care reprezintă valoarea lui π (pi).
        *   `sin(...)`: Calculează sinusul unghiului în radiani.
        *   `%4.3f`: Formatează rezultatul ca un număr cu virgulă mobilă cu o lățime totală de 4 caractere și 3 zecimale, urmat de un spațiu.
    *   `printf("%3c",'|');`: Afișează caracterul '|' cu o lățime de 3 caractere.
*   `return 0;`: Returnează 0 pentru a indica faptul că programul s-a executat cu succes.

**Ce face programul:**

Programul calculează și afișează valorile sinus pentru un set de unghiuri (0, 30, 45, 60 și 90 de grade).  Afișează unghiurile și valorile sinus într-un format tabelar, folosind caractere '|' pentru a delimita coloanele.

**Ieșirea programului:**

```
|    |   |   0 |   30 |   45 |   60 |   90 |
0.000 |   0.500 |   0.707 |   0.866 |   1.000 |
```

Prima linie afișează unghiurile (aproximativ, deoarece sunt convertite la întregi pentru afișare). A doua linie afișează valorile sinus corespunzătoare, formatate cu 3 zecimale.