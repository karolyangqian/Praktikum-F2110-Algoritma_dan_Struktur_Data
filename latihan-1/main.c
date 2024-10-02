#include <stdio.h>
#include "point.h"
#include "circle.h"
#include "fraction.h"
#include "rotating_point.h"
#include "complex.h"

int main() {
    // POINT a, b, c;
    // CreatePoint(&a, 0, 0);
    // CreatePoint(&b, 2, 0);
    // CreatePoint(&c, 5, 0);
    // CIRCLE c1, c2;
    // CreateCIRCLE(&c1, Absis(a), Ordinat(a), 2);
    // CreateCIRCLE(&c2, Absis(c), Ordinat(c), Panjang(b, c));
    // printf("%d", IsCIRCLESIntersects(c2, c1));
    // WriteCIRCLE(c1);
    // FRACTION frac1, frac2, frac3;
    // ReadFRACTION(&frac1);
    // WriteFRACTION(frac1); printf("\n");
    // CreateFRACTION(&frac2, 4, 6);
    // WriteFRACTION(frac2), printf("\n");
    // WriteFRACTION(SimplifyFRACTION(frac2)); printf("\n");
    // frac3 = MultiplyNumberFRACTION(3, frac1);
    // WriteFRACTION(frac3);
    POINT p;
    CreatePoint(&p, 0.5, 0.5);
    COMPLEX c;
    CreateComplex(&c, 1.5, 0.5);
    int n = 2;
    TransformPointByComplexPower(&p, c, 0);
    return 0;
}