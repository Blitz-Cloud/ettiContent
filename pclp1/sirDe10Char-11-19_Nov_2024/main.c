#include <ctype.h>
#include <stdio.h>


int main(void) {
    int i;
    char v[11],cmd;
    while(1) {
        for(i=0; i<=10; i++) {
            v[i]= 'a'+i;
        }
        v[i]=="\0";
        for(i=10; i>=0; i--) {
            printf("%c",v[i]);
        }
        printf("\n");
        printf("Sa se introduca o comanda:\nD/d pentru ca relua programul\t N/n pentru nu\n ");
        cmd=getchar();
        getchar();
        cmd = tolower(cmd);
        switch (cmd) {
            case 'd':
                break;
            case 'n':
                return 0;
                break;
        }

    }
    return 0;
}
