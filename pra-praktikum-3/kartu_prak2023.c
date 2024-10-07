#include "listdin.h"
#include <stdio.h>

#define CAP 100000

int main() {
    ListDin l1, l2, l3;
    int i, j = 0;
    CreateListDin(&l1, CAP);
    CreateListDin(&l2, CAP);
    CreateListDin(&l3, 2*CAP);

    readList(&l1);
    readList(&l2);

    while (i < listLength(l1) || j < listLength(l2)) {
        if (ELMT(l2, j) > ELMT(l1, i)) {
            insertLast(&l3, ELMT(l2, j));
            j++;
        } else {
            insertLast(&l3, ELMT(l1, i));
            i++;
        }
    }
    printList(l3);
    return 0;
}