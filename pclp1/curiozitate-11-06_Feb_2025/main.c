#include <stdio.h>

int suma(int *a,int *b){
    *a = 8;
    return *a + *b;
}

int main(void) {
    int a = 1, b = 3;
    printf("%d", suma(&a, &b));
    printf("%d", a);
    return 0;
}
