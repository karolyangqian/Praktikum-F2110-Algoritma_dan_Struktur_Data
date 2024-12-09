#include "list_circular.h"
#include <stdio.h>
#include <stdlib.h>

void rotate(List *l, int k) {
    int cur;
    for (int i = 0; i < k; i++) {
        deleteFirst(l, &cur);
        insertLast(l, cur);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    List l;
    CreateList(&l);

    int x, max = -9999, idx;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x > max) {
            max = x;
            idx = i;
        }
        insertLast(&l, x);
    }

    rotate(&l, idx);

    displayList(l);
    return 0;
}