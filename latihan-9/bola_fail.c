#include <stdio.h>
#include "list_circular.h"

int main() {
    int n;
    scanf("%d", &n);

    List l;
    CreateList(&l);
    int res = 0;
    boolean out[n];
    
    for (int i = 0; i < n-1; i++) {
        int x;
        scanf("%d", &x);
        insertLast(&l, x);
    }

    for (int i = 0; i < n; i++) {
        out[i] = false;
    }

    while (!isEmpty(l)) {
        int mov;
        deleteFirst(&l, &mov);

        if (mov > 0) {
            for (int i = 0; i < mov; i++) {
                res = (res + 1) % n;
                while (out[res]) {
                    res = (res + 1) % n;
                }
            }
        } else {
            for (int i = 0; i < -mov; i++) {
                res = (res - 1 + n) % n;
                while (out[res]) {
                    res = (res - 1 + n) % n;
                }
            }
        }
        out[res] = true;
    }

    for (int i = 0; i < n; i++) {
        if (!out[i]) {
            res = i;
            break;
        }
    }

    printf("%d\n", res+1);
    return 0;
}