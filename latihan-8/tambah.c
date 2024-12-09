#include "listlinier.h"
#include <stdlib.h>
#include <stdio.h>



int main() {
    List l1; CreateList(&l1);
    List l2; CreateList(&l2);
    int a;

    scanf("%d", &a);
    while (a != -1) {
        insertFirst(&l1, a);
        scanf("%d", &a);
    }

    scanf("%d", &a);
    while (a != -1) {
        insertFirst(&l2, a);
        scanf("%d", &a);
    }

    // displayList(l1); displayList(l2);

    List res; CreateList(&res);
    int curi, carry = 0;
    Address p1 = FIRST(l1), p2 = FIRST(l2);
    while (p1 != NULL && p2 != NULL) {
        curi = INFO(p1) + INFO(p2) + carry;
        if (curi > 9) {
            carry = 1;
            curi %= 10;
        } else carry = 0;
        insertFirst(&res, curi);
        p1 = NEXT(p1);
        p2 = NEXT(p2);
    }

    while (p1 != NULL) {
        curi = INFO(p1) + carry;
        if (curi > 9) {
            carry = 1;
            curi %= 10;
        } else carry = 0;
        insertFirst(&res, curi);
        p1 = NEXT(p1);
    }

    while (p2 != NULL) {
        curi = INFO(p2) + carry;
        if (curi > 9) {
            carry = 1;
            curi %= 10;
        } else carry = 0;
        insertFirst(&res, curi);
        p2 = NEXT(p2);
    }
    // displayList(res);

    if (carry > 0) {
        Address f = newNode(carry);
        NEXT(f) = FIRST(res);
        FIRST(res) = f;
    }

    Address p;
    p = FIRST(res);

    while (p != NULL) {
        printf("%d", INFO(p));
        p = NEXT(p);
        if (p != NULL) printf(" ");
    }
    printf("\n");


    return 0;
}