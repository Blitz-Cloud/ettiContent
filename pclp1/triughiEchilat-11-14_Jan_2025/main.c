#include <stdio.h>
#include <math.h>

struct TriunghiEchilateral {
    int lat;
    int perimetru;
    float arie;
};

void vedere (struct TriunghiEchilateral tr) {
    printf("Vedere echilateral:\n");
    printf("Lat = %d\n", tr.lat);
    printf("Perimetru = %d\n", tr.perimetru);
    printf("Arie = %f\n", tr.arie);
}


int main(void) {
    int latura;
    struct TriunghiEchilateral tr;
    scanf("%d", &latura);
    tr.lat = latura;
    tr.perimetru = latura*3;
    tr.arie = (float)latura* sqrt(3)/4.0;
    vedere(tr);
    return 0;
}

`