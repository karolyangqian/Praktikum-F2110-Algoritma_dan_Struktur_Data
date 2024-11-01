#include "matrix.h"
#include <stdio.h>
const int mod = 1e9+7;

int jalur(Matrix *mat, int i, int j) {
    // base
    if(ROW_EFF(*mat)-i == 1 && COL_EFF(*mat)-j == 1) {
        return 1;
    }
    else {
        int k = 0;
        // printf("R\n");
        if ((j + 1) < COL_EFF(*mat) && ELMT(*mat, i, j+1) == 0) {
            // printf("%d %d\n", i, j+1);
            k += jalur(mat, i, j+1);
            k %= mod;
        }
        // printf("D\n");
        if ((i+1) < ROW_EFF(*mat) && ELMT(*mat, i+1, j) == 0) {
            // printf("%d %d\n", i+1, j);
            k += jalur(mat, i+1, j);
            k %= mod;
        }
        return k;
    }
}

int main(int argc, char const *argv[])
{
    int N;
    Matrix mat;
    scanf("%d", &N);
    readMatrix(&mat, N, N);

    int k;
    k = jalur(&mat, 0, 0);
    k = k%(1000000000 + 7);
    printf("%d\n", k);
    return 0;
}
