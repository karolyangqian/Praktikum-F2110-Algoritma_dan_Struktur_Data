#include <stdio.h>
#include "list_circular.h"

void rotate(List *l, int k) {
    int cur;
    for (int i = 0; i < k; i++) {
        deleteFirst(l, &cur);
        insertLast(l, cur);
    }
}

boolean formasi (int n, List l) {
    if (n <= 2) return true;

    Address p = FIRST(l);
    int prev;
    prev = INFO(p);
    p = NEXT(p);
    int d;
    if ((prev+1)%n == INFO(p)%n) d = 1;
    else d = -1;
    for (int i = 1; i < n; i++) {
        if ((prev + d)%n != INFO(p)%n) return false;
        else {
            // printf("y\n");
            prev = INFO(p);
            p = NEXT(p);
        }
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);

    List l;
    CreateList(&l);
    int x;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insertLast(&l, x);
    }

    boolean f = formasi(n, l);
    if (f) printf("YES\n");
    else printf("NO\n");
    
    return 0;
}