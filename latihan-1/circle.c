#include "circle.h"
#include "point.h"
#include <stdio.h>

#define PI 3.14
#define EPSILON 0.000001

boolean IsCIRCLEValid(float X, float Y, float R) 
/* Mengirim TRUE jika X, Y, R dapat membentuk Lingkaran C yang valid */
{
    return R > 0;
}

/* *** Konstruktor: Membentuk Lingkaran C dari titik pusat dan radius *** */
void CreateCIRCLE(CIRCLE *C, float X, float Y, float R)
/* Membentuk sebuah CIRCLE dari komponen-komponen yang valid */
/* Prekondisi : X, Y, R, valid */
{
    CreatePoint(&Center(*C), X, Y);
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
            break;
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
    printf("P(%.2f,%.2f) r=%.2f", Absis(Center(C)), Ordinat(Center(C)), Radius(C));
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
boolean IsPOINTInsideCIRCLE(CIRCLE C, POINT P)
/* Mengirim true jika titik P berada di dalam lingkaran C */
{
    return Radius(C) > Panjang(Center(C), P);
}

boolean IsPOINTInEdgeCIRCLE(CIRCLE C, POINT P)
/* Mengirim true jika titik P berada di tepi lingkaran C */
/* HINT: Gunakan toleransi kecil untuk komparasi float */
{
    return fabs(Panjang(Center(C), P) - Radius(C)) < EPSILON;
}

boolean IsCIRCLEInsideCIRCLE(CIRCLE C1, CIRCLE C2)
/* Mengirim true jika C1 di dalam C2 atau C2 di dalam C1 */
/* NOTE: Tidak berpotongan/ bersinggungan */
{
    float minRadius = (Radius(C1) < Radius(C2)) ? Radius(C1) : Radius(C2);
    float maxRadius = (Radius(C1) > Radius(C2)) ? Radius(C1) : Radius(C2);
    return (Panjang(Center(C1), Center(C2)) + minRadius) < maxRadius;
}

boolean IsCIRCLESTangents(CIRCLE C1, CIRCLE C2)
/* Mengirim true jika C1 bersinggungan di 1 titik dengan C2 */
/**
 * HINT: Terdapat 2 Kemungkinan:
 *  1. Bersinggungan dalam
 *  2. Bersinggungan luar
 */
{
    // float minRadius = (Radius(C1) < Radius(C2)) ? Radius(C1) : Radius(C2);
    // float maxRadius = (Radius(C1) > Radius(C2)) ? Radius(C1) : Radius(C2);
    boolean bersinggunganLuar = (Panjang(Center(C1), Center(C2))) == (Radius(C1) + Radius(C2));
    boolean bersinggunganDalam = (Panjang(Center(C1), Center(C2)) == fabs(Radius(C1) - Radius(C2)));
    return bersinggunganLuar || bersinggunganDalam;
}

boolean IsCIRCLESIntersects(CIRCLE C1, CIRCLE C2)
/* Mengirim true jika C1 berpotongan di 2 titik dengan C2 */
{
    // float minRadius = (Radius(C1) < Radius(C2)) ? Radius(C1) : Radius(C2);
    // float maxRadius = (Radius(C1) > Radius(C2)) ? Radius(C1) : Radius(C2);
    boolean menyatu = Panjang(Center(C1), Center(C2)) < (Radius(C1) + Radius(C2));
    return menyatu && (Panjang(Center(C1), Center(C2)) > fabs(Radius(C1) - Radius(C2)));
    //    intersectLuar                          IntersectDalam
}