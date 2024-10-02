#include "rotating_point.h"
#include "complex.h"
#include "point.h"
#include <stdio.h>

/* Catatan: Hasil perkalian float dan int adalah float*/

/* Fungsi untuk menghitung perpangkatan bilangan kompleks */
/* Formula: Bilangan kompleks dikalikan dirinya sendiri sebanyak P kali */
COMPLEX PowerCOMPLEX(COMPLEX C, int p) {
    COMPLEX result = C;
    for (int i = 1; i < p; i++) {
        result = MultiplyCOMPLEX(result, C);
    }
    return result;
}

void TransformPointByComplexPower(POINT *P, COMPLEX C, int n) {
    if(n == 0){
        printf("Titik keluar dari lingkaran pada iterasi ke 0");
        return;
    }
    int i;
    float x, y;
    COMPLEX pC = C;
    for (i = 1; i <= n; i++) {
        x = Absis(*P) * Real(pC) - Ordinat(*P) * Imag(pC);
        y = Absis(*P) * Imag(pC) + Ordinat(*P) * Real(pC);
        Absis(*P) = x;
        Ordinat(*P) = y;
        pC = MultiplyCOMPLEX(pC, C);
        if (Jarak0(*P) > 1.0) {
            printf("Titik keluar dari lingkaran pada iterasi ke %d", i);
            return;
        }
    }
    printf("Titik tetap berada di dalam lingkaran setelah %d iterasi", n);
}


// float x, y;
    // int i = 0;
    // COMPLEX pC = C;
    // while (i < n && Jarak0(*P) <= 1.0) {;
    //     x = Absis(*P) * Real(pC) - Ordinat(*P) * Imag(pC);
    //     y = Absis(*P) * Imag(pC) + Ordinat(*P) * Real(pC);
    //     Absis(*P) = x;
    //     Ordinat(*P) = y;
    //     pC = MultiplyCOMPLEX(pC, C);
    //     i++;
    // }
    // if (i < n || Jarak0(*P) > 1) printf("Titik keluar dari lingkaran pada iterasi ke %d", i);
    // else printf("Titik tetap berada di dalam lingkaran setelah %d iterasi", n);