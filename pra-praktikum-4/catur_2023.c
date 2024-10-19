#include "matrix.h"
#include <stdio.h>

int main() {
    Matrix M;
    readMatrix(&M, 8, 8);
    int p = 0;
    int h = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if(ELMT(M, i, j) == 1) {
                if ((i+j) % 2 == 0) h++;
                else p++;
            }
        }
    }

    printf("%d %d\n", h, p);
    return 0;
}