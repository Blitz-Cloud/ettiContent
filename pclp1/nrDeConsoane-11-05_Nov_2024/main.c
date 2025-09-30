
#include <stdio.h>

int main(void) {
    int i=0;
    for(;i<=15;i++) {
        i%2==1?printf("%5.2d ",i): 0 ;
    }
    printf("\n");
    for(i=0;i<=15;i++) {
        i%2==0?printf("%5.2d ",i): 0;
    }
    return 0;
}

`