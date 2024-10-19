#include "liststatik.h"
#include <stdio.h>

int main() {
    ListStatik a1, a2, result;
    CreateListStatik(&a1);
    CreateListStatik(&a2);
    CreateListStatik(&result);
    readList(&a1);
    readList(&a2);

    int lenDiff;
    if (listLength(a1) < listLength(a2)) {
        lenDiff = listLength(a2) - listLength(a1);
        for (int i = 0; i < lenDiff; i++) insertFirst(&a1, 0);
    } else {
        lenDiff = listLength(a1) - listLength(a2);
        for (int i = 0; i < lenDiff; i++) insertFirst(&a2, 0);
    }

    result = plusMinusList(a1, a2, true);
    for (int i = listLength(result)-1; i > 0; i--){
        if (ELMT(result, i) > 9) {
            ELMT(result, i) %= 10;
            ELMT(result, i-1) += 1;
        }
    }
    if (ELMT(result, 0) > 9) {
        ELMT(result, 0) %= 10;
        insertFirst(&result, 1);
    }
    printList(result);
    return 0;
}