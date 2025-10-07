
#include <stdio.h>

struct test{
char name;
char name1;
short name5;
};

int main(void) {
    printf("%u\n", sizeof(struct test));
    return 0;
}
