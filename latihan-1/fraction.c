#include <stdio.h>
#include "fraction.h"

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

boolean IsFRACTIONValid(int N, int D)
/* Mengirim TRUE jika pecahan valid */
{
    return D != 0;
}

/* *** Konstruktor: Membentuk FRACTION F dari komponen-komponennya *** */
void CreateFRACTION(FRACTION *F, int N, int R)
/* Membentuk sebuah FRACTION yang valid */
/* Prekondisi : N, R valid */
{
    Numerator(*F) = N;
    Denominator(*F) = R;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void ReadFRACTION(FRACTION *F)
/**
 * I.S. : F tidak terdefinisi
 * F.S. : F terdefinisi dan merupakan FRACTION yang valid
 * Proses : Mengulangi membaca komponen N, R sehingga membentuk F
 *  - Pembacaan dilakukan dengan mengetikkan komponen N, R dalam
 *    1 baris, dipisah spasi, diakhiri enter.
 *  - Jika FRACTION tidak valid, maka berikan pesan: "FRACTION tidak valid"
 *    dengan newline, pembacaan diulangi hingga didapat FRACTION yang valid.
 */
 {
    int n, r;
    while(true) {
        scanf("%d %d", &n, &r);
        if (!IsFRACTIONValid(n, r)) {
            printf("FRACTION tidak valid\n");
        }
        else return;
    }
    CreateFRACTION(F, n, r);
 }

void WriteFRACTION(FRACTION F)
/**
 * I.S. : F sembarang
 * F.S. : Nilai F ditulis dengan format "N/R"
 * Proses : Penulisan tanpa spasi, enter, atau karakter lain di depan, 
 * belakang, atau di antaranya
 * NOTE: hasil dalam bentuk paling sederhana
 */
 {
    int fpb = gcd(Numerator(F), Denominator(F));
    printf("%d/%d", Numerator(F)/fpb, Denominator(F)/fpb);
 }

/* ***************************************************************** */
/* KELOMPOK OPERASI DASAR TERHADAP TYPE                              */
/* ***************************************************************** */
/* NOTE: untuk hasil FRACTION = 0, maka kembalikan 0/1 */

FRACTION AddFRACTION(FRACTION F1, FRACTION F2)
/* Mengirim hasil penjumlahan F1 + F2 */
/* NOTE: hasil dalam bentuk paling sederhana */
{
    FRACTION FRes = {
        .N = (Numerator(F1) * Denominator(F2) + Numerator(F2) * Denominator(F1)),
        .D = Denominator(F1) * Denominator(F2)
    };
    int fpb = gcd(Numerator(FRes), Denominator(FRes));
    Numerator(FRes) /= fpb;
    Denominator(FRes) /= fpb;
    return FRes;
}

FRACTION SubtractFRACTION(FRACTION F1, FRACTION F2)
/* Mengirim hasil pengurangan F1 - F2 */
/* NOTE: hasil dalam bentuk paling sederhana */
{
    Numerator(F2) *= -1;
    return AddFRACTION(F1, F2);
}

FRACTION MultiplyFRACTION(FRACTION F1, FRACTION F2)
/* Mengirim hasil perkalian F1 * F2 */
/* NOTE: hasil dalam bentuk paling sederhana */
{
    FRACTION FProd = {
        .N = Numerator(F1) * Numerator(F2),
        .D = Denominator(F1) * Denominator(F2)
    }
    int fpb = gcd(Numerator(FProd), Denominator(FProd));
    Numerator(FProd) /= fpb;
    Denominator(FProd) /= fpb;
    return FProd;
}

FRACTION DivideFRACTION(FRACTION F1, FRACTION F2)
/* Mengirim hasil pembagian F1 / F2 */
/* Prekondisi: F2 tidak nol */
/* NOTE: hasil dalam bentuk paling sederhana */
{
    int temp = Numerator(F2);
    Numerator(F2) = Denominator(F2);
    Denominator(F2) = temp;
    return MultiplyFRACTION(F1, F2);
}

FRACTION MultiplyNumberFRACTION(int n, FRACTION F1)
/* Mengirim hasil perkalian n * F1 */
/* NOTE: hasil dalam bentuk paling sederhana */
{
    return MultiplyFRACTION(F1, {.N = n, .R = 1});
}

/* ***************************************************************** */
/* KELOMPOK OPERASI LAIN TERHADAP TYPE                               */
/* ***************************************************************** */
FRACTION SimplifyFRACTION(FRACTION F)
/* Mengembalikan FRACTION dalam bentuk sederhana */
/* NOTE: pastikan hanya numerator yang memiliki nilai negatif */
{

}

float ToDecimal(FRACTION F)
/* Mengonversi FRACTION ke bentuk desimal */
{

}