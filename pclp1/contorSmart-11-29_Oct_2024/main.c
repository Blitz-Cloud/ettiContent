
#include <stdio.h>

void main(void) {
    float n=0;
    for (;n<=10;n=n+1) {
        printf("%4.0f ",n);
    }
    printf("\n");
    for (n=10;n<=15;n=n+0.5) {
        printf("%.1f ",n);
    }
    printf("\n");
    for (n=15;n<=16;n=n+0.1) {
        printf("%.1f ",n);
    }printf("%.1f ",n);
}
