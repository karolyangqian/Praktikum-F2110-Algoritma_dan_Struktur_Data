#include "liststatik.h"
#include <stdio.h>

int main() {
    ListStatik a1, a2;
    CreateListStatik(&a1); CreateListStatik(&a2);
    readList(&a1); readList(&a2);

    for (int i = 0; i < listLength(a2); i++) {
        insertLast(&a1, ELMT(a2, i));
    }
    sortList(&a1, true);
    printList(a1);
    return 0;
}