#include "listdin.h"
#include <stdio.h>

// void insertAt(ListDin *l, int idx, int val) {
//     for (int i = listLength(*l) - 1; i >= idx; i--)
//     {
//         ELMT(*l, i + 1) = ELMT(*l, i);
//     }
//     ELMT(*l, idx) = val;
//     NEFF(*l)++;
// }

boolean checkIntersect(int L1, int R1, int L2, int R2) {
    return (L2 <= R1 && L1 <= R2) || (L1 <= R2 && L2 <= R1);
}


int main() {
    ListDin intervalay, newArray;
    CreateListDin(&intervalay, 1000);
    CreateListDin(&newArray, 1000+2);
    readList(&intervalay);
    int a, b;
    scanf("%d %d", &a, &b);

    int i = 0;
    while (ELMT(intervalay, i) < a && i < listLength(intervalay)) {
        insertLast(&newArray, ELMT(intervalay, i));
        i++;
    }

    if (i % 2 == 0) insertLast(&newArray, a);

    while (ELMT(intervalay, i) <= b) {
        i++;
    }

    if (i % 2 == 0) {
        insertLast(&newArray, b);
    }

    while (i < listLength(intervalay)) {
        insertLast(&newArray, ELMT(intervalay, i));
        i++;
    }



    for (int i = 0; i < listLength(newArray); i++) {
        printf("%d", ELMT(newArray, i));
        if (i != listLength(newArray)-1) printf(" ");
    }
    printf("\n");
    return 0;
}