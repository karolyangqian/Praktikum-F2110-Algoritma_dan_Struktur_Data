#include <stdio.h>
#include "stack.h"

void sortirKeranjang(Stack *s1, Stack *s2) {
    CreateEmpty(s2);
    int temp, j, x;

    while (!IsEmpty(*s1)) {
        Pop(s1, &temp);
        j = 0;
        while (!IsEmpty(*s2) && temp < InfoTop(*s2)) {
            Pop(s2, &x);
            // printf("%d ", x);
            Push(s1, x);
            j++;
        }
        Push(s2, temp);
        for (int i = 0; i < j; i++) {
            Pop(s1, &x);
            Push(s2, x);
        }
    }
}

int main() {
    Stack s, sorted;
    int N;
    CreateEmpty(&s);
    scanf("%d", &N);

    int x;

    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        Push(&s, x);
    }

    sortirKeranjang(&s, &sorted);

    for (int i = 0; i < N; i++) {
        printf("%d ", sorted.T[i]);
    }
    printf("\n");

    
    
    return 0;
}