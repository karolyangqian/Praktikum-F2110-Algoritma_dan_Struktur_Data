#include "matrix.h"
#include <stdio.h>

int kekacauan(Matrix mat, int n, int r, int c) {
    int k = 0;
    
    for (int i = 0; i < n; i++) {
        if (i != c) k = (k+ELMT(mat, r, i))%(1000000000 + 7);
        if(i != r) k=(k+ELMT(mat, i, c))%(1000000000 + 7);
    }
    return k;
}

int main(int argc, char const *argv[])
{
    int N;
    Matrix mat;
    scanf("%d", &N);
    readMatrix(&mat, N, N);

    int k = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++){
            if (ELMT(mat, i, j) != 0) {
                k = (k+kekacauan(mat, N, i, j))%(1000000000 + 7);
            }
        }
    }
    printf("%d\n", k);
    return 0;
}
