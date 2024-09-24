#include <stdio.h>
#include "complex.h"

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsCOMPLEXValid(float Re, float Im) {
    return true;
}

void CreateComplex(COMPLEX *C, float Re, float Im) {
    Real(*C) = Re;
    Imag(*C) = Im;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaCOMPLEX(COMPLEX *C) {
    float Re, Im;
    scanf("%f %f", &Re, &Im);
    CreateComplex(C, Re, Im);
}

void TulisCOMPLEX(COMPLEX C) {
    if (Imag(C) < 0) {
        printf("%.2f%.2fi\n", Real(C), Imag(C));
    } else {
        printf("%.2f+%.2fi\n", Real(C), Imag(C));
    }
}

/* ***************************************************************** */
/* KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE                         */
/* ***************************************************************** */
COMPLEX AddCOMPLEX(COMPLEX C1, COMPLEX C2) {
    COMPLEX CSum;
    Real(CSum) = Real(C1) + Real(C2);
    Imag(CSum) = Imag(C1) + Imag(C2);
    return CSum;
}

COMPLEX SubtractCOMPLEX(COMPLEX C1, COMPLEX C2) {
    COMPLEX CDif;
    Real(CDif) = Real(C1) - Real(C2);
    Imag(CDif) = Imag(C1) - Imag(C2);
    return CDif;
}

COMPLEX MultiplyCOMPLEX(COMPLEX C1, COMPLEX C2) {
    COMPLEX CProd;
    Real(CProd) = (Real(C1) * Real(C2)) - (Imag(C1) * Imag(C2));
    Imag(CProd) = (Real(C1) * Imag(C2)) + (Imag(C1) * Real(C2));
    return CProd;
}

COMPLEX DivideCOMPLEX(COMPLEX C1, COMPLEX C2) {
    float denominator = Real(C2)*Real(C2) + Imag(C2)*Imag(C2);
    COMPLEX numerator;

    if (denominator != 0) {
        Imag(C2) = -1 * Imag(C2);
        numerator = MultiplyCOMPLEX(C1, C2);
        Real(numerator) = Real(numerator) / denominator;
        Imag(numerator) = Imag(numerator) / denominator;
        return numerator;
    } else {
        CreateComplex(&numerator, 0, 0);
        return numerator;
    }
}

/* ***************************************************************** */
/* KELOMPOK OPERASI LAIN TERHADAP TYPE                               */
/* ***************************************************************** */
float AbsCOMPLEX(COMPLEX C) {
    return sqrt(pow(Real(C), 2) + pow(Imag(C), 2));
}

COMPLEX ConjugateCOMPLEX(COMPLEX C) {
    Imag(C) = -1 * Imag(C);
    return C;
}

/* *** Kelompok Operator Relational *** */
boolean CEQ(COMPLEX C1, COMPLEX C2) {
    return (Real(C1) == Real(C2)) && (Imag(C1) == Imag(C2));
}

boolean CNEQ(COMPLEX C1, COMPLEX C2) {
    return !CEQ(C1, C2);
}