#include <stdio.h>


void linieTabel() {
    int j;
    printf("|");
    for(j=1;j<=10;j++) {
       printf("%3s","-");
    }
    printf("  |\n");
}

int main(void) {
    int i,j;
    linieTabel();
    for(i=1;i<=10;i++) {
        printf("|");
        for(j=1;j<=10;j++) {
            if(i==j || i+j==11 || i<j && i+j<=11 ) {
                printf("%3c",'x');
            }else {
                printf("%3c",' ');
            }
        }
        printf("  |\n");
        }
    linieTabel();
}

`