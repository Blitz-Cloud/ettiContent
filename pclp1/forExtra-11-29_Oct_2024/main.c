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
