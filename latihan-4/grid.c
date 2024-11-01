#include <stdio.h>
#include "matrix.h"
const int mod = 1e9+7;

int main() {
    int n;
    scanf("%d", &n);

    Matrix m;
    readMatrix(&m, n, n);

    Matrix mk;
    createMatrix(n, n, &mk);

    ELMT(mk, 0, 0) = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (ELMT(m, i, j) != 1) {
                if (i > 0) {
                    ELMT(mk, i, j) += ELMT(mk, i-1, j);
                    ELMT(mk, i, j) %= mod;
                }
                if (j > 0)
                {
                    ELMT(mk, i, j) += ELMT(mk, i, j-1);
                    ELMT(mk, i, j) %= mod;
                }
                
            }
        }
        
    }


    printf("%d\n", ELMT(mk, n-1, n-1));
    
    return 0;
}