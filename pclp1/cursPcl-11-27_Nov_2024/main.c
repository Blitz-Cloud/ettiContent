
```c

#include <stdio.h>

int main(void) {
    printf("Hello, World!\n");
    return 0;
}

```

Acest cod C este un program foarte simplu care afișează textul "Hello, World!" în consolă. Iată o explicație detaliată:

**1. Include-uri:**

*   `#include <stdio.h>`: Include fișierul antet standard pentru intrare/ieșire, necesar pentru funcția `printf`.

**2. Funcția `main()`:**

*   `int main(void)`: Definește funcția principală a programului, care nu primește argumente.  Aceasta este funcția de unde începe execuția programului.
*   `printf("Hello, World!\n");`: Această linie este cea mai importantă.
    *   `printf()`: Este o funcție din biblioteca standard C care este folosită pentru a afișa text în consolă.
    *   `"Hello, World!\n"`: Acesta este un șir literal (un șir de caractere încadrat între ghilimele duble) care conține textul pe care dorim să-l afișăm.
    *   `\n`: Acesta este un caracter special numit "newline".  Atunci când este inclus într-un șir, acesta determină ca cursorul să se mute la începutul liniei următoare după ce textul este afișat.
*   `return 0;`: Returnează 0 pentru a indica faptul că programul s-a executat cu succes.  Aceasta este o convenție standard în C.

**Ce face programul:**

Programul afișează pur și simplu textul "Hello, World!" în consolă și apoi trece la linia următoare.

**Ieșirea programului:**

```
Hello, World!
```

Acesta este un program clasic folosit adesea ca prim exemplu în introducerile în programare, deoarece demonstrează structura de bază a unui program C și modul de afișare a textului.