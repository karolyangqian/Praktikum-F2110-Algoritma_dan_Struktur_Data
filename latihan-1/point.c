#include <stdio.h>
#include "point.h"

#define PI acos(-1)

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
void CreatePoint (POINT * P, float X, float Y) {
    Absis(*P) = X;
    Ordinat(*P) = Y;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaPOINT (POINT * P) {
    float x, y;
    scanf("%f %f", &x, &y);
    CreatePoint(P, x, y);
}

void TulisPOINT (POINT P) {
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}         

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2) {
    return (Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2));
}

boolean NEQ (POINT P1, POINT P2) {
    return !EQ(P1, P2);
}

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P) {
    return (Absis(P) == 0) && (Ordinat(P) == 0);
}

boolean IsOnSbX (POINT P) {
    return Ordinat(P) == 0;
}

boolean IsOnSbY (POINT P) {
    return Absis(P) == 0;
}

int Kuadran (POINT P) {
    if (Absis(P) > 0) {
        if (Ordinat(P) > 0) return 1;
        else return 4;
    } else {
        if (Ordinat(P) > 0) return 2;
        else return 3;
    }
}


POINT NextX (POINT P) {
    Absis(P)++;
    return P;
}

POINT NextY (POINT P) {
    Ordinat(P)++;
    return P;
}

POINT PlusDelta (POINT P, float deltaX, float deltaY) {
    Absis(P) = Absis(P) + deltaX;
    Ordinat(P) = Ordinat(P) + deltaY;
    return P;
}

POINT MirrorOf (POINT P, boolean SbX) {
    if (SbX) Ordinat(P) = -1 * Ordinat(P);
    else Absis(P) = -1 * Absis(P);
    return P;
}

float Jarak0 (POINT P) {
    return sqrt(Absis(P)*Absis(P) + Ordinat(P)*Ordinat(P));
}

float Panjang (POINT P1, POINT P2) {
    float a, b;
    a = Absis(P2) - Absis(P1);
    b = Ordinat(P2) - Ordinat(P1);
    return sqrt(a*a + b*b);
}

void Geser (POINT *P, float deltaX, float deltaY) {
    *P = PlusDelta(*P, deltaX, deltaY);
}

void GeserKeSbX (POINT *P) {
    Ordinat(*P) = 0;
}

void GeserKeSbY (POINT *P) {
    Absis(*P) = 0;
}

void Mirror (POINT *P, boolean SbX) {
    if (SbX) Ordinat(*P) = -1 * Ordinat(*P);
    else Absis(*P) = -1 * Absis(*P);
}

void Putar (POINT *P, float Sudut) {
    float SudutRadian = Sudut * PI / 180;
    CreatePoint(P, Absis(*P)*cos(SudutRadian) + Ordinat(*P)*sin(SudutRadian), -Absis(*P)*sin(SudutRadian) + Ordinat(*P)*cos(SudutRadian));
}

void PersamaanLinearDuaVariabel (POINT P1, POINT P2) {
    int a, b;
    a = (Ordinat(P2) - Ordinat(P1)) / (Absis(P2) - Absis(P1));
    b = Ordinat(P1) - a * Absis(P1);
    printf("(%d,%d)\n", a, b);
}