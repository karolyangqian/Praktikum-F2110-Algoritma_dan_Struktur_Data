#include "listdin.h"
#include <stdio.h>

#define NMAX 100000

int main() {
    ListDin mi, ma, L;
    CreateListDin(&L, NMAX);
    CreateListDin(&mi, NMAX);
    CreateListDin(&ma, NMAX);
    readList(&L);

    int mie = 0;
    int mae = 1000001;

    for (int i = 0; i < listLength(L); i++) {
        if (ELMT(L, i) > mie) {
            insertLast(&mi, ELMT(L, i));
            mie = ELMT(mi, i);
        } else {
            insertLast(&mi, mie);
        }
    }


    for (int i = listLength(L)-1; i >= 0; i--) {
        if (ELMT(L, i) < mae) {
            insertLast(&ma, ELMT(L, i));
            mae = ELMT(L, i);
        } else {
            insertLast(&ma, mae);
        }
    }

    int count = 0;
    for (int i = 0; i < listLength(L); i++) {
        if (ELMT(L, i) >= ELMT(mi, i) && ELMT(L, i) <= ELMT(ma, listLength(ma)-1-i)) {
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}