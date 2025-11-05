
#include <stdio.h>

int main(void) {
    int i,j,n;
    printf("Sa se introduca dimensiunea matricii: ");
    scanf("%d",&n);
    int a[100][100];

    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            printf("Se citeste elementul:[%d,%d] ",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    printf("Se afiseaza matricea\n");
    for(i=0;i<n;i++) {
        for (j=0;j<n;j++) {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
