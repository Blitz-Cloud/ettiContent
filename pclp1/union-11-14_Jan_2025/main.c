
```c
#include <stdio.h>

union A{
    int val,val1;
};

int main(void) {
    union A nr;
    scanf("%d",&nr.val);
    printf("%o\n", nr.val);
    return 0;
}

```

Acest cod C face următoarele:

1.  **Include fișierul antet `stdio.h`:**
    *   `#include <stdio.h>`: Include fișierul antet standard pentru intrare/ieșire, necesar pentru funcțiile `printf` și `scanf`.

2.  **Definește o uniune (union) numită `A`:**
    *   ```c
        union A{
            int val,val1;
        };
        ```
        *   O uniune este o structură de date specială în care toți membrii împărtășesc aceeași locație de memorie.  Aceasta înseamnă că doar unul dintre membrii uniunii poate fi activ la un moment dat.
        *   `int val, val1;`: Uniunea `A` are doi membri, ambii de tip `int`: `val` și `val1`.  Deoarece sunt într-o uniune, `val` și `val1` ocupă aceeași locație de memorie.

3.  **Funcția `main()`:**
    *   ```c
        int main(void) {
            union A nr;
            scanf("%d",&nr.val);
            printf("%o\n", nr.val);
            return 0;
        }
        ```
        *   `union A nr;`: Declară o variabilă `nr` de tipul uniunii `A`.
        *   `scanf("%d",&nr.val);`: Citește un număr întreg de la utilizator și îl stochează în membrul `val` al uniunii `nr`.
        *   `printf("%o\n", nr.val);`: Afișează valoarea stocată în membrul `val` al uniunii `nr` în format octal (baza 8).  `%o` este specificatorul de format pentru afișarea unui număr întreg fără semn în octal.  `\n` adaugă un caracter newline la sfârșitul liniei.
        *   `return 0;`: Returnează 0 pentru a indica faptul că programul s-a executat cu succes.

**Ce face programul:**

Programul solicită utilizatorului să introducă un număr întreg, apoi afișează acel număr în format octal.

**Exemplu de execuție:**

```
10
12
```

În acest exemplu, utilizatorul a introdus numărul 10. Programul a afișat 12, care este reprezentarea octală a numărului 10.

**Observații:**

*   Deoarece `val` și `val1` împărtășesc aceeași locație de memorie, modificarea unuia dintre ele va afecta și valoarea celuilalt.  În acest program, se citește valoarea în `nr.val` și se afișează `nr.val`, deci utilizarea uniunii nu este neapărat necesară.  S-ar putea folosi o variabilă `int` simplă.
*   Scopul principal al uniunilor este de a economisi memorie atunci când se știe că doar unul dintre membrii uniunii va fi folosit la un moment dat.  În acest caz, nu există o economie semnificativă de memorie, deoarece ambele variabile sunt de tip `int`.
*   Programul nu validează intrarea utilizatorului. Dacă utilizatorul introduce un caracter în loc de un număr întreg, `scanf` va eșua, iar valoarea lui `nr.val` va rămâne neinițializată, ceea ce va duce la un comportament imprevizibil.