
#include <stdio.h>

int main(void) {
    int i, k = 0;
    double s = 0;
    for (i = 1; i <=2025;i++){
        s += i;
        // printf("%d ", i);
        if (i % 5 == 0)
        {
            i += 5;
            k++;
        }
    }

    printf("\n%lf", s);
    printf("\n%d", k);
}

`