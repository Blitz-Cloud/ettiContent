
#include <stdio.h>

int main(void) {
    char c;
    for(c='a';c<='k';c++) {
        printf("%3c",c);
    }
    printf("\n");
    for(c='L';c<='Z';c++) {
        printf("%3c",c);
    }
    return 0;
}
