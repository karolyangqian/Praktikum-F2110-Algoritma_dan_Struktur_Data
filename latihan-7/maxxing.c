#include <stdio.h>
#include "prioqueue.h"

int main() {
    int n; scanf("%d", &n);
    // Tambahkan inisialisasi yang dibutuhkan

    PrioQueue qa, qb;
    CreatePrioQueue(&qa);
    CreatePrioQueue(&qb);
    
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        enqueue(&qa, a);
        // Tambahkan inisialisasi yang dibutuhkan
    }

    for (int i = 0; i < n; i++) {
        int b; scanf("%d", &b);
        enqueue(&qb, b);
        // Tambahkan inisialisasi yang dibutuhkan
    }

    long long ans = 0;
    int a;
    int b;
    // Lanjutkan kode perhitungan disini
    for (int i = 0; i < n; i++) {
        dequeue(&qa, &a);
        dequeue(&qb, &b);
        ans += (long long)a*b;
    }

    printf("%lld\n", ans);
}