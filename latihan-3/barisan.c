#include "listdin.h"
#include <stdio.h>

void insertAt(ListDin *l, int idx, int val) {
    for (int i = listLength(*l) - 1; i >= idx; i--)
    {
        ELMT(*l, i + 1) = ELMT(*l, i);
    }
    ELMT(*l, idx) = val;
    NEFF(*l)++;
}

int main() {
    ListDin l, newl;
    CreateListDin(&l, 1000);
    CreateListDin(&newl, 1000);

    readList(&l);
    int steps = 0;
    int j;
    insertLast(&newl, ELMT(l, 0));
    for (int i = 1; i < listLength(l); i++)
    {
        j = i - 1;
        // printf("%d %d\n", ELMT(l, i), ELMT(newl, j));
        while (ELMT(l, i) < ELMT(newl, j) && j >= 0)
        {
            j--;
            steps++;
        }
        insertAt(&newl, j+1, ELMT(l, i));
    }
    // printList(newl);
    printf("%d\n", steps);
    return 0;
}