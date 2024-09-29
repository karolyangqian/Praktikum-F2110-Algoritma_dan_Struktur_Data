#include "liststatik.h"
#include <stdio.h>

int main() {
    ListStatik l; CreateListStatik(&l);
    readList(&l);
    printf("%d", listLength(l));
    insertFirst(&l, 10);
    printList(l); printf("\n");
    int val;
    deleteAt(&l, &val, 0);
    printList(l); printf("\n");
    int min, max;
    extremeValues(l, &max, &min);
    printf("%d %d", min, max);

    // sortList(&l, false);
    // printList(l);
    // insertAt(&l, 10, 3);
    // printList(l);
    // ElType val;
    // deleteFirst(&l, &val);
    // printList(l);
    // printf("\n");
    // ListStatik l1; CreateListStatik(&l1);
    // ListStatik l2; CreateListStatik(&l2);
    // printf("l1:\n");
    // readList(&l1);
    // printf("l2:\n");
    // readList(&l2);
    // ListStatik plus = plusMinusList(l1, l2, true);
    // ListStatik min = plusMinusList(l1, l2, false);
    // printList(plus);
    // printf("\n");
    // printList(min);
    // printf("\n");
    return 0;
}