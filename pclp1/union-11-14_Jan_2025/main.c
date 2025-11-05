#include <stdio.h>

union A{
    int val,val1;
};

int main(void) {
    union A nr;
    scanf("%d",&nr.val);
    printf("%o\n", nr.val);
    return 0;
}
