#include "listrec.h"

// ElType last ()

List susun(List l) {
    if (length(l) <= 2) return l;
    else {
        List rec = susun(deleteLast(tail(l)));
        return konso(rec, head(l));
    }
}

int main() {
    List l = NULL;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        l = konsb(l, x);
    }

    List temp = copy(l);
    List rev = reverseList(l);
    List res = NULL;
    for (int i = 0; i < n/2; i++) {
        res = konsb(res, head(l));
        res = konsb(res, head(rev));
        l = deleteFirst(l);
        rev = deleteFirst(rev);
        
    }

    if (n%2 != 0) {
        res = konsb(res, getMiddle(temp));
    }

    displayList(res);
}