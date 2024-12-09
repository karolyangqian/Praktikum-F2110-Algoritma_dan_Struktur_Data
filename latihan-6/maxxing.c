#include <stdio.h>
#include "boolean.h"
#include "stack.h"

const int MXN = 1e4 + 7;
Stack temp;

int maxKekuatanX(Stack *s, int X) {
    CreateEmpty(&temp);
    int n = Top(*s) - X + 2;
    int min, max, x;

    for (int i = 0; i < n; i++) {
        min = InfoTop(*s);
        max = InfoTop(*s);
        for
    }
}

int main()
{
    // Start code here...
    int N;


    scanf("%d", N);

    for (int i = 0; i < N; i++) {

    }


    return 0;
}