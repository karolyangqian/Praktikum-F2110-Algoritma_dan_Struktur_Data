#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    List l; CreateList(&l);
    Address p;
    int a;


    scanf("%d", &a);
    while (a != -9999) {
        if (isEmpty(l)) {
            insertLast(&l, a);
        } else {
            p = FIRST(l);
            int loc = 0;
            while (p != NULL && a > INFO(p)) {
                p = NEXT(p);
                loc++;
            }
            insertAt(&l, a, loc);
        }
        scanf("%d", &a);
    }

    displayList(l);
    return 0;
}