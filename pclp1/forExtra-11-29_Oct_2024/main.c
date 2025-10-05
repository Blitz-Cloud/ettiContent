
```c
#include <stdio.h>

int main(void) {
    int i=1;
    for (i;i<=10;i++) {
        printf("%3d",i);
    }
    printf("\n");
    for (i=10;i>=1;i--) {
        printf("%3d",i);
    }
    return 0;
}

```

Acest cod C afișează două secvențe de numere întregi în consolă. Iată o explicație detaliată:

**1. Include-uri:**

*   `#include <stdio.h>`: Include fișierul antet standard pentru intrare/ieșire, necesar pentru funcția `printf`.

**2. Funcția `main()`:**

*   `int main(void)`: Definește funcția principală a programului, care nu primește argumente.
*   `int i=1;`: Declară o variabilă întreagă `i` și o inițializează cu valoarea 1. Această variabilă va fi folosită ca contor în bucle.
*   `for (i;i<=10;i++) { printf("%3d",i); }`: Această buclă `for` afișează numerele de la 1 la 10.
    *   `i;`: Aceasta este clauza de inițializare a buclei `for`. Deoarece `i` a fost deja inițializat înainte de buclă, această clauză este goală.
    *   `i<=10;`: Aceasta este clauza de condiție a buclei `for`. Bucla va continua să ruleze atâta timp cât `i` este mai mic sau egal cu 10.
    *   `i++`: Aceasta este clauza de incrementare a buclei `for`. După fiecare iterație a buclei, valoarea lui `i` este incrementată cu 1.
    *   `printf("%3d",i);`: Afișează valoarea lui `i` cu o lățime de 3 caractere. Formatul `%3d` asigură că numerele sunt aliniate corect, chiar dacă au mai puține de 3 cifre.
*   `printf("\n");`: Afișează un caracter newline pentru a trece la linia următoare.
*   `for (i=10;i>=1;i--) { printf("%3d",i); }`: Această buclă `for` afișează numerele de la 10 la 1 în ordine descrescătoare.
    *   `i=10;`: Aceasta este clauza de inițializare a buclei `for`. Valoarea lui `i` este setată la 10.
    *   `i>=1;`: Aceasta este clauza de condiție a buclei `for`. Bucla va continua să ruleze atâta timp cât `i` este mai mare sau egal cu 1.
    *   `i--`: Aceasta este clauza de decrementare a buclei `for`. După fiecare iterație a buclei, valoarea lui `i` este decrementată cu 1.
    *   `printf("%3d",i);`: Afișează valoarea lui `i` cu o lățime de 3 caractere.
*   `return 0;`: Returnează 0 pentru a indica faptul că programul s-a executat cu succes.

**Ce face programul:**

Programul afișează două linii de numere. Prima linie conține numerele de la 1 la 10, iar a doua linie conține numerele de la 10 la 1. Numerele sunt aliniate corect folosind specificatorul de format `%3d`.

**Ieșirea programului:**

```
  1  2  3  4  5  6  7  8  9 10
 10  9  8  7  6  5  4  3  2  1
```