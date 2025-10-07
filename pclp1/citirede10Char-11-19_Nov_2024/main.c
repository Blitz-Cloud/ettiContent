
#include <stdio.h>

int main(void) {
    char a[11],in;
    int i;
    for(i=0;i<3;i++) {
        in = getchar();
        getchar();
        a[i]=in;
    }
    a[i]='\0';
    for(i=2;i>=0;i--) {
        printf("%c",a[i]);
    }

    return 0;
}
