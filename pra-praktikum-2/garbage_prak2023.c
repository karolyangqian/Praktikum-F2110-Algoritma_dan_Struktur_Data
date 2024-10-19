#include "liststatik.h"
#include <stdio.h>

int ambilSampah(ListStatik rumah, ListStatik perjalanan, int jenisSampah) {
    int waktuPerjalanan = 0;
    int waktuSampah = 0;
    int i = 0;
    while (indexOf(rumah, jenisSampah) != IDX_UNDEF && i < listLength(rumah)) {
        if (i > 0) waktuPerjalanan += ELMT(perjalanan, i-1);
        if (ELMT(rumah, i) == jenisSampah) { 
            waktuSampah += 1;
            ELMT(rumah, i) = 0;
        }
        i++;
    }
    waktuPerjalanan *= 2;
    return waktuPerjalanan + waktuSampah;
}

int main() {
    ListStatik rumah, perjalanan;
    CreateListStatik(&rumah); CreateListStatik(&perjalanan);
    readList(&rumah);
    readList(&perjalanan);

    int sum = 0;

    // besi
    int besi = ambilSampah(rumah, perjalanan, 1);
    sum += besi;
    printf("%d\n", besi);
    // kertas
    int kertas = ambilSampah(rumah, perjalanan, 2);
    sum += kertas;
    printf("%d\n", kertas);
    // glass
    int glass = ambilSampah(rumah, perjalanan, 3);
    sum += glass;
    printf("%d\n", glass);
    printf("%d\n", sum);
    return 0;
}