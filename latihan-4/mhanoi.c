#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int m[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &m[i][j]);
        }
    }
    
    int p[2][2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &p[i][j]);
        }
    }
    int tot = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1; j++) {
            for (int c = 0; c < 4; c++) {
                int t = 1;
                for (int a = i; a < i+2; a++) {
                    for (int b = j; b < j+2; b++) {
                        if (m[a][b] <= p[a-i][b-j]) {
                            t = 0;
                        }
                    }
                }
                if(t) {
                    tot++;
                    break;
                }
                int temp = p[0][0];
                p[0][0] = p[0][1];
                p[0][1] = p[1][1];
                p[1][1] = p[1][0];
                p[1][0] = temp;
            }
        }
    }
    printf("%d\n", tot);
    return 0;
}