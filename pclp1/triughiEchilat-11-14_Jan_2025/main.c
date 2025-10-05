
```c
#include <stdio.h>
#include <math.h>

struct TriunghiEchilateral {
    int lat;
    int perimetru;
    float arie;
};

void vedere (struct TriunghiEchilateral tr) {
    printf("Vedere echilateral:\n");
    printf("Lat = %d\n", tr.lat);
    printf("Perimetru = %d\n", tr.perimetru);
    printf("Arie = %f\n", tr.arie);
}


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

Acest cod C manipulează un tablou de numere întregi, afișându-l inițial, apoi adăugând 10 la fiecare element și afișând din nou tabloul modificat. Iată o explicație detaliată:

**1. Include-uri:**

*   `#include <stdio.h>`: Include fișierul antet standard pentru intrare/ieșire, necesar pentru funcția `printf`.

**2. Funcția `main()`:**

*   `int main(void)`: Definește funcția principală a programului, care nu primește argumente.
*   `int a[10]={1,2,3,4,5,6,7,8,9,10};`: Declară și inițializează un tablou de 10 numere întregi numit `a` cu valorile 1, 2, 3, 4, 5, 6, 7, 8, 9 și 10.
*   `for(int i=0;i<10;i++) { printf("%d ",*(a+i)); }`: Această buclă `for` iterează prin elementele tabloului `a` și afișează fiecare element.
    *   `*(a+i)`: Această expresie accesează elementul de la indexul `i` al tabloului `a`.  În C, numele unui tablou (e.g., `a`) este echivalent cu un pointer către primul element al tabloului.  Adăugând `i` la `a` (e.g., `a + i`) se obține un pointer către elementul de la indexul `i`.  Operatorul `*` (dereferențiere) este folosit pentru a accesa valoarea de la adresa indicată de pointer.  Deci, `*(a + i)` este echivalent cu `a[i]`.
    *   `printf("%d ",*(a+i));`: Afișează valoarea elementului curent urmată de un spațiu.
*   `for(int i=0;i<10;i++) { *(a+i)=*(a+i)+10; }`: Această buclă `for` iterează prin elementele tabloului `a` și adaugă 10 la fiecare element.
    *   `*(a+i)=*(a+i)+10;`: Adaugă 10 la valoarea elementului de la indexul `i` și stochează rezultatul înapoi în același element.
*   `printf("\n");`: Afișează un caracter newline pentru a trece la linia următoare.
*   `for(int i=0;i<10;i++) { printf("%d ",*(a+i)); }`: Această buclă `for` iterează din nou prin elementele tabloului `a` și afișează fiecare element (care acum are valoarea inițială + 10).
*   `return 0;`: Returnează 0 pentru a indica faptul că programul s-a executat cu succes.

**Ce face programul:**

1.  Inițializează un tablou de 10 numere întregi cu valorile de la 1 la 10.
2.  Afișează elementele tabloului pe o singură linie, separate prin spații.
3.  Adaugă 10 la fiecare element al tabloului.
4.  Afișează din nou elementele tabloului pe o singură linie, separate prin spații.

**Ieșirea programului:**

```
1 2 3 4 5 6 7 8 9 10 
11 12 13 14 15 16 17 18 19 20 
```

Prima linie afișează valorile inițiale ale tabloului, iar a doua linie afișează valorile după ce s-a adăugat 10 la fiecare element.