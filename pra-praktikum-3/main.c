#include "listdin.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    ListDin l, l2, l3;
    CreateListDin(&l, 3);
    CreateListDin(&l2, 3);

    for (int i = 0; i < CAPACITY(l); i++) {
        printf("%d ", ELMT(l, i));
    }
    printf("\n");
    printList(l); printf("\n");
    readList(&l);
    readList(&l2);
    // sort(&l, false);
    l3 = plusMinusList(l, l2, true);
    printList(l3);
    dealocateList(&l);
    return 0;
}