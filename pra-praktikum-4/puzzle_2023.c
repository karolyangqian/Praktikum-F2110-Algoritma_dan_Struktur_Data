#include "matrix.h"
#include <stdio.h>

int main() {
    int N, M, K, A, B;
    Matrix mat, sub;
    scanf("%d %d", &N, &M);
    readMatrix(&mat, N, M);

    scanf("%d", &K);

    int isSub = 1;
    for (int k = 0; k < K; k++) {
        scanf("%d %d", &A, &B);
        readMatrix(&sub, A, B);
        isSub = 0;
        for (int n = 0; n < N-A+1; n++) {
            for (int m = 0; m < M-B+1; m++) {
                if (ELMT(sub, 0, 0) == ELMT(mat, n, m)) {
                    // printf("%d %d", ELMT(sub, 0, 0), ELMT(mat, n, m));
                    int stopped = 0;
                    for (int a = 0; a < A; a++) {
                        for (int b = 0; b < B; b++) {
                            // printf("%d %d\n", ELMT(mat, n+a, m+b), ELMT(sub, a, b));
                            if (ELMT(mat, n+a, m+b) != ELMT(sub, a, b)) {
                                stopped = 1;
                                break;
                            }
                        }
                        if (stopped) break;
                    }
                    if (!stopped) {
                        isSub = 1;
                        printf("current true\n");
                        break;
                    }
                }
            }
            if (isSub) break;
        }
        if (!isSub) break;
    }

    if (isSub) printf("true\n");
    else printf("false\n");

    return 0;
}