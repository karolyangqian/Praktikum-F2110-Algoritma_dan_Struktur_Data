#include "listrec.h"
#include <stdio.h>
#include <stdlib.h>

void mergeSortedUnique(List l1, List l2, List *res) {
    if (!isEmpty(l1) && !isEmpty(l2)) {
        if (head(l1) < head(l2)) {
            *res = konsb(*res, head(l1));
            mergeSortedUnique(tail(l1), l2, res);
        } else if (head(l2) < head(l1)) {
            *res = konsb(*res, head(l2));
            mergeSortedUnique(l1, tail(l2), res);
        } else {
            *res = konsb(*res, head(l1));
            mergeSortedUnique(tail(l1), tail(l2), res);
        }
    }

    else if (!isEmpty(l1)) {
        *res = concat(*res, l1);
    }

    else if (!isEmpty(l2)) {
        *res = concat(*res, l2);
    }

}

// int main() {
//     List l1 = NULL, l2 = NULL;
//     int n;
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++)
//     {
//         int x;
//         scanf("%d", &x);
//         l1 = konsb(l1, x);
//     }
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++)
//     {
//         int x;
//         scanf("%d", &x);
//         l2 = konsb(l2, x);
//     }
//     List res = NULL;
//     mergeSortedUnique(l1, l2, &res);
//     displayList(res);
// }