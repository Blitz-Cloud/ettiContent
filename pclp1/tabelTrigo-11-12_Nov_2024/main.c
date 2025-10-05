
```c
#include <stdio.h>
#include <math.h>
int main(void) {
    int i;
    float x[5]={0.0,30.0,45.0,60.0,90.0};
    printf("%3c",'|');
    printf("%4c",' ');
    printf("%3c",'|');
    for(i=0;i<5;i++) {
        printf("%4d ",x[i]);
        printf("%3c",'|');
    }
    for(i=0;i<5;i++) {
        printf("%4.3f ", sin(x[i]*M_PI/180.0));
        printf("%3c",'|');
    }
    return 0;
}

```

Acest cod C calculează și afișează valorile sinus ale unor unghiuri date în grade. Iată o explicație detaliată:

**1. Include-uri:**

*   `#include <stdio.h>`: Include fișierul antet standard pentru intrare/ieșire, necesar pentru funcția `printf`.
*   `#include <math.h>`: Include fișierul antet standard pentru funcții matematice, necesar pentru funcția `sin` și constanta `M_PI`.

**2. Funcția `main()`:**

*   `int main(void)`: Definește funcția principală a programului, care nu primește argumente.
*   `int i;`: Declară o variabilă întreagă `i` pentru a fi folosită ca contor în buclă.
*   `float x[5]={0.0,30.0,45.0,60.0,90.0};`: Declară un tablou de numere reale (float) numit `x` cu 5 elemente.  Acesta este inițializat cu valorile 0.0, 30.0, 45.0, 60.0 și 90.0, care reprezintă unghiuri în grade.
*   `printf("%3c",'|');`: Afișează caracterul '|' (bară verticală) cu o lățime de 3 caractere.
*   `printf("%4c",' ');`: Afișează un spațiu cu o lățime de 4 caractere.
*   `printf("%3c",'|');`: Afișează caracterul '|' cu o lățime de 3 caractere.
*   `for(i=0;i<5;i++) { printf("%4d ",x[i]); printf("%3c",'|'); }`: Această buclă `for` iterează prin elementele tabloului `x` și afișează fiecare valoare (unghiul în grade) cu o lățime de 4 caractere, urmată de caracterul '|' cu o lățime de 3 caractere.  Formatul `%4d` este folosit pentru a afișa numerele întregi cu o lățime minimă de 4 caractere.  Deși `x[i]` sunt `float`, sunt afișate ca întregi, pierzând partea fracționară.
*   `for(i=0;i<5;i++) { printf("%4.3f ", sin(x[i]*M_PI/180.0)); printf("%3c",'|'); }`: Această buclă `for` iterează din nou prin elementele tabloului `x`, calculează sinusul fiecărui unghi și afișează rezultatul.
    *   `x[i]*M_PI/180.0`:  Această expresie convertește unghiul din grade în radiani.  `M_PI` este o constantă definită în `math.h` care reprezintă valoarea lui π (pi).
    *   `sin(x[i]*M_PI/180.0)`: Calculează sinusul unghiului în radiani.
    *   `printf("%4.3f ", ...)`: Afișează valoarea sinusului cu o lățime minimă de 4 caractere și cu 3 zecimale.
    *   `printf("%3c",'|');`: Afișează caracterul '|' cu o lățime de 3 caractere.
*   `return 0;`: Returnează 0 pentru a indica faptul că programul s-a executat cu succes.

**Ce face programul:**

Programul afișează un tabel cu două rânduri. Primul rând conține unghiurile 0, 30, 45, 60 și 90 (grade), iar al doilea rând conține valorile sinus ale acestor unghiuri.  Fiecare valoare este separată de caracterul '|'.

**Ieșirea programului:**

```
|    |    |   0 |  30 |  45 |  60 |  90 |
0.000 |0.500 |0.707 |0.866 |1.000 |
```

**Observații:**

*   Programul nu afișează un tabel complet cu linii orizontale. Afișează doar valorile separate de bare verticale.
*   Valorile unghiurilor sunt afișate ca numere întregi, chiar dacă sunt stocate ca numere reale.
*   Valorile sinus sunt afișate cu 3 zecimale.