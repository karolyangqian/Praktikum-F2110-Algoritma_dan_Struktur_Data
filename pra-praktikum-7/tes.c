#include <stdio.h>
#include "queue.h"

int main() {
    Queue q;
    CreateQueue(&q);
    enqueue(&q, 1);
    printf("halo\n");
    return 0;
}