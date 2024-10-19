#include "matrix.h"
#include <stdio.h>

int jalur(Matrix *mat, int i, int j) {
    if (ROW_EFF(*mat)-i == 1 && COL_EFF(*mat)-j == 1) {
        return 1;
    }
    else {
        int k =0;
        if ((j+1) < COL_EFF(*mat) && ELMT(*mat, i, j+1) == 0) {
            k += jalur(mat, i, j+1);
        }
        if((i+1) < COL_EFF(*mat) && ELMT(*mat, i+1, j) == 0) {
            k += jalur(mat, i+1, j);
        }
        return k;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    Matrix mat;
    readMatrix(&mat, n, n);

    int k = jalur(&mat, 0, 0);

    printf("%d\n", k);

    return 0;
}