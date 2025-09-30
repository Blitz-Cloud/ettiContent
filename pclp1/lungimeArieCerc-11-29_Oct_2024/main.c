
#include <stdio.h>

int main(void) {
    float raza=6.12345;
    float pi = 3.1415;
    float area=pi*raza*raza;
    float len = 2*pi*raza;
    printf("Area: %11.7e\n",area);
    printf("Length: %11.7e\n",len);

    return 0;
}

`