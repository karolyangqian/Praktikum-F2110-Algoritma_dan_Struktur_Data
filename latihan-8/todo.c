#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    List l; CreateList(&l);
    char op;
    int a, idx;
    Address p;

    scanf(" %c", &op);
    while (op != 'X') {
        if (op == 'P') {
            scanf("%d", &a);
            insertFirst(&l, a);
        } else if (op == 'I') {
            scanf("%d", &a);
            insertLast(&l, a);
        } else if (op == 'C') {
            if (!isEmpty(l)) {
                p = FIRST(l);
                FIRST(l) = NEXT(p);
                free(p);
            }
        } else if (op == 'D') {
            scanf("%d", &a);
            idx = indexOf(l, a);
            if (idx != IDX_UNDEF) {
                deleteAt(&l, idx, &a);
            }
        }
        scanf(" %c", &op);
    }
    displayList(l);
    return 0;
}