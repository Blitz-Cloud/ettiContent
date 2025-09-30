#include <stdio.h>
#include <math.h>

int main(void) {
    printf("Valoare tanusului %d este de %0.3f\n",0, 1/tan(0.0* M_PI/180.0));
    printf("Valoare tanusului %d este de %0.3f\n",30, 1/tan(30.0* M_PI/180.0));
    printf("Valoare tanusului %d este de %0.3f\n",45, 1/tan(45.0* M_PI/180.0));
    printf("Valoare tanusului %d este de %0.3f\n",60, 1/tan(60.0* M_PI/180.0));
    printf("Valoare tanusului %d este de %0.3f\n",90, 1/tan(90.0* M_PI/180.0));
    return 0;
}

`