#include <stdio.h>
#include "list_circular.h"

void geser(Address *p, int mov, int curlen){

    if (mov > 0){
        mov %= curlen;
    }
    else{
        mov = (-1*mov)%curlen;
        mov = curlen-mov;
    }
    for (int i = 0; i < mov; i++){
        *p = NEXT(*p);
    }
}

Address prev(Address P){
    Address last = P;
    while (NEXT(last) != P){
        last = NEXT(last);
    }
    return last;
}

int main() {
    int n;
    scanf("%d", &n);

    List l;
    CreateList(&l);
    int x;
    int movdir[n-1];
    for (int i = 0; i < n; i++) {
        if (i < n-1) {
            scanf("%d", &x);
            movdir[i] = x;
        }
        insertLast(&l, i+1);
    }

    Address p = FIRST(l), prevP;
    int mov, len = n;
    boolean delOrigin = false;
    for (int i = 0; i < n-1; i++) {
        mov = movdir[i];
        if (i > 0) {
            if (mov > 0)  {
                geser(&p, 1, len);
                mov--;
            } else {
                geser(&p, -1, len);
                mov++;
            }
            len--;
            NEXT(prevP) = NEXT(NEXT(prevP));
        }
        geser(&p, mov, len);
        prevP = prev(p);
    }

    printf("%d\n", INFO(NEXT(p)));
    return 0;
}