
```c

#include <stdio.h>

int main(void) {
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    for(int i=0;i<10;i++) {
        printf("%d ",*(a+i));
    }
    for(int i=0;i<10;i++) {
        *(a+i)=*(a+i)+10;
    }
    printf("\n");
    for(int i=0;i<10;i++) {
        printf("%d ",*(a+i));
    }
    return 0;
}

```

Acest cod C manipulează un tablou de numere întregi, afișând elementele sale inițiale și apoi elementele după ce au fost incrementate cu 10. Iată o explicație detaliată:

**1. Include-uri:**

*   `#include <stdio.h>`: Include fișierul antet standard pentru intrare/ieșire, necesar pentru funcția `printf`.

**2. Funcția `main()`:**

*   `int main(void)`: Definește funcția principală a programului, care nu primește argumente.
*   `int a[10]={1,2,3,4,5,6,7,8,9,10};`: Declară și inițializează un tablou de numere întregi numit `a` cu 10 elemente. Elementele sunt inițializate cu valorile 1, 2, 3, 4, 5, 6, 7, 8, 9 și 10.
*   `for(int i=0;i<10;i++) { printf("%d ",*(a+i)); }`: Această buclă `for` iterează prin elementele tabloului `a` și afișează fiecare element.
    *   `*(a+i)`: Aceasta este o modalitate de a accesa elementele unui tablou folosind aritmetica pointerilor. `a` este un pointer către primul element al tabloului. `a + i` calculează adresa celui de-al `i`-lea element al tabloului. `*(a + i)` dereferențiază această adresă, adică obține valoarea stocată la acea adresă.  Este echivalent cu `a[i]`.
    *   `printf("%d ",*(a+i));`: Afișează valoarea elementului curent urmată de un spațiu.
*   `for(int i=0;i<10;i++) { *(a+i)=*(a+i)+10; }`: Această buclă `for` iterează prin elementele tabloului `a` și incrementează fiecare element cu 10.
    *   `*(a+i)=*(a+i)+10;`: Adaugă 10 la valoarea elementului curent și stochează rezultatul înapoi în același element.
*   `printf("\n");`: Afișează un caracter newline pentru a trece la linia următoare.
*   `for(int i=0;i<10;i++) { printf("%d ",*(a+i)); }`: Această buclă `for` iterează din nou prin elementele tabloului `a` și afișează fiecare element (după ce a fost incrementat cu 10).
*   `return 0;`: Returnează 0 pentru a indica faptul că programul s-a executat cu succes.

**Ce face programul:**

1.  Inițializează un tablou de numere întregi cu valorile de la 1 la 10.
2.  Afișează elementele tabloului.
3.  Incrementează fiecare element al tabloului cu 10.
4.  Afișează din nou elementele tabloului (după incrementare).

**Ieșirea programului:**

```
1 2 3 4 5 6 7 8 9 10
11 12 13 14 15 16 17 18 19 20
```