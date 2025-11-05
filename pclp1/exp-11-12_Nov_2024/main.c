#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int i;
    div_t x;
    for(i=11;i<20;i++) {
        x = div(i,7);
        printf("%d : %d,%d\n",i,x.quot,x.rem);
    }
    return 0;
}
