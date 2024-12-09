#include <stdio.h>
#include "prioqueue.h"

int main() {
    PrioQueue q;
    CreatePrioQueue(&q);
    int a, b;
    displayPrioQueue(q);
    printf("h: %d t: %d\n", IDX_HEAD(q), IDX_TAIL(q));
    while (true)
    {
        scanf("%d", &a);
        if (a == 1) {
            scanf("%d", &b);
            enqueue(&q, b);
        }
        else if (a == 2)
        {
            dequeue(&q, &b);
        }
        displayPrioQueue(q);
        printf("h: %d t: %d\n", IDX_HEAD(q), IDX_TAIL(q));
        
    }
    return 0;
}