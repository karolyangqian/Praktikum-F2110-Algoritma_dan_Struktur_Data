#include "circle.h"
#include "point.h"
#include <stdio.h>
#include <math.h>

#define PI 3.14

boolean IsCIRCLEValid(float X, float Y, float R) 
/* Mengirim TRUE jika X, Y, R dapat membentuk Lingkaran C yang valid */
{
    return R != 0;
}

/* *** Konstruktor: Membentuk Lingkaran C dari titik pusat dan radius *** */
void CreateCIRCLE(CIRCLE *C, float X, float Y, float R)
/* Membentuk sebuah CIRCLE dari komponen-komponen yang valid */
/* Prekondisi : X, Y, R, valid */
{
    Absis(Center(*C)) = X;
    Ordinat(Center(*C)) = Y;
    // CreatePoint(&Center(*C), X, Y);
    Radius(*C) = R;
}
/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void ReadCIRCLE(CIRCLE *C)
/**
 * I.S. : C tidak terdefinisi
 * F.S. : C terdefinisi dan merupakan CIRCLE yang valid
 * Proses : Mengulangi membaca komponen X, Y, R sehingga membentuk C
 *  - Pembacaan dilakukan dengan mengetikkan komponen X, Y, R dalam
 *    1 baris, dipisah spasi, diakhiri enter.
 *  - Jika CIRCLE tidak valid, maka berikan pesan: "CIRCLE tidak valid"
 *    dengan newline, pembacaan diulangi hingga didapat CIRCLE yang valid.
 */
{
    float x, y, r;
    boolean valid = false;
    while(!valid) {
        scanf("%f %f %f", &x, &y, &r);
        valid = IsCIRCLEValid(x, y, r);
        if (valid) {
            CreateCIRCLE(C, x, y, r);
            return;
        }
        printf("CIRCLE tidak valid\n");
    }

}

void WriteCIRCLE(CIRCLE C)
/**
 * I.S. : C sembarang
 * F.S. : Nilai C ditulis dengan format "P(X,Y) r=R", ex: P(1,1) r=5
 * Proses : Penulisan tanpa spasi, enter, atau karakter lain di depan, 
 * belakang, atau di antaranya
 */
{
    printf("P(%.2f,%.2f)r=%.2f", Absis(Center(C)), Ordinat(Center(C)), Radius(C));
}

/* ***************************************************************** */
/* KELOMPOK OPERASI GEOMETRI TERHADAP TYPE                           */
/* ***************************************************************** */
float Circumference(CIRCLE C)
/* Menghitung keliling lingkaran: K = 2 * π * r, π = 3.14 */
{
    return 2 * PI * Radius(C);
}

float Area(CIRCLE C)
/* Menghitung luas lingkaran: A = π * r^2, π = 3.14 */
{
    return PI * Radius(C) * Radius(C);
}

/* ***************************************************************** */
/* KELOMPOK OPERASI LAIN TERHADAP TYPE                               */
/* ***************************************************************** */
// float Panjang (POINT P1, POINT P2) {
//     float a, b;
//     a = Absis(P2) - Absis(P1);
//     b = Ordinat(P2) - Ordinat(P1);
//     return sqrt(a*a + b*b);
// }
boolean IsPOINTInsideCIRCLE(CIRCLE C, POINT P)
/* Mengirim true jika titik P berada di dalam lingkaran C */
{
    return Radius(C) > sqrt(pow(Absis(P) - Absis(Center(C)), 2) + pow(Ordinat(P) - Ordinat(Center(C)), 2));
}

boolean IsPOINTInEdgeCIRCLE(CIRCLE C, POINT P)
/* Mengirim true jika titik P berada di tepi lingkaran C */
/* HINT: Gunakan toleransi kecil untuk komparasi float */
{
    float a = Radius(C) - sqrt(pow(Absis(P) - Absis(Center(C)), 2) + pow(Ordinat(P) - Ordinat(Center(C)), 2));
    return a < 0.01 && a > -0.01;
}

boolean IsCIRCLEInsideCIRCLE(CIRCLE C1, CIRCLE C2)
/* Mengirim true jika C1 di dalam C2 atau C2 di dalam C1 */
/* NOTE: Tidak berpotongan/ bersinggungan */
{
    float a = Radius(C1) - Radius(C2);
    if (a < 0) a *= -1;
    return Panjang(Center(C1), Center(C2)) < a;
}

boolean IsCIRCLESTangents(CIRCLE C1, CIRCLE C2)
/* Mengirim true jika C1 bersinggungan di 1 titik dengan C2 */
/**
 * HINT: Terdapat 2 Kemungkinan:
 *  1. Bersinggungan dalam
 *  2. Bersinggungan luar
 */
{
    float a = Radius(C1) - Radius(C2);
    if (a < 0) a *= -1;
    return ((Panjang(Center(C1), Center(C2)) == a) && (Radius(C1) != Radius(C2))) || (Panjang(Center(C1), Center(C2)) == (Radius(C1) + Radius(C2)));
}

boolean IsCIRCLESIntersects(CIRCLE C1, CIRCLE C2)
/* Mengirim true jika C1 berpotongan di 2 titik dengan C2 */
{
    return true;
}