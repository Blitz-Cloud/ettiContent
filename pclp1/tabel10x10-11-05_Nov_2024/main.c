
#include <ctype.h>
#include <stdio.h>

int main(void) {
    char c, copy, cmd='d';
    c = getchar();
    getchar();
    while (cmd=='d') {
        copy =  'a' <=c && c<='z' ? toupper(c): tolower(c);
        printf("litera %c a devenit %c\n",c,copy);
        copy = c;
        printf("D continua transformarile N iese din program\n");
        cmd = getchar();
        cmd = tolower(cmd);
        getchar();
    }
    return 0;
}

`