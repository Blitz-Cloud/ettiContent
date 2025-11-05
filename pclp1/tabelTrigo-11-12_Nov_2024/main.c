#include <stdio.h>
#include <math.h>
int main(void) {
    int i;
    float x[5]={0.0,30.0,45.0,60.0,90.0};
    printf("%3c",'|');
    printf("%4c",' ');
    printf("%3c",'|');
    for(i=0;i<5;i++) {
        printf("%4d ",x[i]);
        printf("%3c",'|');
    }
    for(i=0;i<5;i++) {
        printf("%4.3f ", sin(x[i]*M_PI/180.0));
        printf("%3c",'|');
    }
    return 0;
}
