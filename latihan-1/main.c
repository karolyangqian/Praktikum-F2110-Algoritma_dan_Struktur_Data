#include <stdio.h>
#include "point.h"
#include "circle.h"

int main() {
    POINT a, b, c;
    CreatePoint(&a, 0, 0);
    CreatePoint(&b, 2, 0);
    CreatePoint(&c, 5, 0);
    CIRCLE c1, c2;
    CreateCIRCLE(&c1, Absis(a), Ordinat(a), 2);
    CreateCIRCLE(&c2, Absis(c), Ordinat(c), Panjang(b, c));
    printf("%d", IsCIRCLESIntersects(c2, c1));
    return 0;
}