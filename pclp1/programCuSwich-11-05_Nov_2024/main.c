
#include <ctype.h>
#include <stdio.h>

int main(void) {
    printf("\tF file  E edit  C compile  R run  Q quit\n");
    printf("Introduceti o optiune:\n");
    char optiune;
    optiune = getchar();
    getchar();
    optiune = tolower(optiune);

    while(optiune) {
        switch (optiune) {
            case 'f':
                printf("File\n");
                break;
            case 'e':
                printf("Edit\n");
                break;
            case 'c':
                printf("Compile\n");
                break;
            case 'r':
                printf("Run\n");
                break;
            case 'q':
                printf("Quit\n");
                return 0;
                break;
        }
        printf("Introduceti o optiune:\n");
        optiune = getchar();
        getchar();
        optiune = tolower(optiune);
    }
    return 0;
}

`