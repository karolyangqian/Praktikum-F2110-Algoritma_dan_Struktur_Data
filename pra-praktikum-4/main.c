#include "matrix.h"
#include <stdio.h>

int main() {
    Matrix m1, m2;
    // readMatrix(&m1, 4, 2);
    // readMatrix(&m2, 2, 3);
    // Matrix m3 = multiplyMatrix(m1, m2);
    // displayMatrix(m3);
    // m2 = multiplyByConst(m2, 2);
    // displayMatrix(m2);
    // if (isIdentity(m1)) printf("identity");
    readMatrix(&m1, 3, 3);
    m1 = transpose(m1);
    displayMatrix(m1);
    pTranspose(&m1);
    displayMatrix(m1);
    if (isSparse(m1)) printf("sparse\n");
    // printf("%.15f\n", determinant(m1));
    return 0;
}