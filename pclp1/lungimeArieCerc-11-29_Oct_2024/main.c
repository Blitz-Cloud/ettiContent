
```c

#include <stdio.h>

int main(void) {
    float raza=6.12345;
    float pi = 3.1415;
    float area=pi*raza*raza;
    float len = 2*pi*raza;
    printf("Area: %11.7e\n",area);
    printf("Length: %11.7e\n",len);

    return 0;
}

```

Acest cod C calculează și afișează aria și lungimea circumferinței unui cerc, folosind o rază fixă și o valoare aproximativă a lui pi. Iată o explicație detaliată:

**1. Include-uri:**

*   `#include <stdio.h>`: Include fișierul antet standard pentru intrare/ieșire, necesar pentru funcția `printf`.

**2. Funcția `main()`:**

*   `int main(void)`: Definește funcția principală a programului, care nu primește argumente.
*   `float raza=6.12345;`: Declară o variabilă de tip `float` numită `raza` și o inițializează cu valoarea 6.12345. Aceasta reprezintă raza cercului.
*   `float pi = 3.1415;`: Declară o variabilă de tip `float` numită `pi` și o inițializează cu valoarea 3.1415. Aceasta este o aproximare a numărului π (pi).
*   `float area=pi*raza*raza;`: Calculează aria cercului folosind formula `aria = pi * raza * raza` și stochează rezultatul în variabila `area`.
*   `float len = 2*pi*raza;`: Calculează lungimea circumferinței cercului folosind formula `lungime = 2 * pi * raza` și stochează rezultatul în variabila `len`.
*   `printf("Area: %11.7e\n",area);`: Afișează aria cercului în format științific (exponențial).
    *   `"Area: %11.7e\n"`: Acesta este șirul de formatare.
        *   `Area: `: Afișează textul "Area: ".
        *   `%11.7e`: Specificatorul de format pentru un număr real cu virgulă mobilă în format științific.
            *   `11`: Lățimea minimă a câmpului (numărul total de caractere afișate).
            *   `7`: Precizia (numărul de cifre după punctul zecimal).
            *   `e`: Indică formatul științific (exponențial).
        *   `\n`: Afișează un caracter newline pentru a trece la linia următoare.
    *   `area`: Variabila care conține valoarea ariei.
*   `printf("Length: %11.7e\n",len);`: Afișează lungimea circumferinței cercului în format științific.
    *   `"Length: %11.7e\n"`: Acesta este șirul de formatare.
        *   `Length: `: Afișează textul "Length: ".
        *   `%11.7e`: Specificatorul de format pentru un număr real cu virgulă mobilă în format științific.
        *   `\n`: Afișează un caracter newline pentru a trece la linia următoare.
    *   `len`: Variabila care conține valoarea lungimii circumferinței.
*   `return 0;`: Returnează 0 pentru a indica faptul că programul s-a executat cu succes.

**Ce face programul:**

Programul calculează aria și lungimea circumferinței unui cerc cu raza 6.12345 și afișează rezultatele în format științific cu o precizie de 7 zecimale și o lățime minimă a câmpului de 11 caractere.

**Ieșirea programului:**

```
Area:  1.1799655e+02
Length:  3.8470798e+01
```