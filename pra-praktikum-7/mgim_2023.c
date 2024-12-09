#include <stdio.h>
#include "queue.h"
#include "boolean.h"

int maxFactor(int N) {
    for (int i = N-1; i >=0; i--) {
        if (N%i == 0) return i;
    }
    return N;
}

int main() {
    
    return 0;
}