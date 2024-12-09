#include "listrec.h"
#include <stdlib.h>
#include <stdio.h>

/* Manajemen Memori */
Address newNode(ElType x) {
    Address p = (Address) malloc(sizeof(Node));
    if (p != NULL) {
        INFO(p) = x;
        NEXT(p) = NIL;
    }
    return p;
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NIL, dan misalnya
   menghasilkan p, maka INFO(p)=x, NEXT(p)=NIL */
/* Jika alokasi gagal, mengirimkan NIL */

/* Pemeriksaan Kondisi List */
boolean isEmpty(List l) {
    return l == NIL;
}
/* Mengirimkan true jika l kosong dan false jika l tidak kosong */
boolean isOneElmt(List l) {
    return !isEmpty(l) && NEXT(l) == NIL;
}
/* Mengirimkan true jika l berisi 1 elemen dan false jika > 1 elemen atau kosong */

/* Primitif-Primitif Pemrosesan List */
ElType head(List l) {
    return INFO(l);
}
/* Mengirimkan elemen pertama sebuah list l yang tidak kosong */
List tail(List l) {
    return NEXT(l);
}
/* Mengirimkan list l tanpa elemen pertamanya, mungkin mengirimkan list kosong */
List konso(List l, ElType e) {
    Address p = newNode(e);
    if (p != NIL) {
        NEXT(p) = l;
        l = p;
    }
    return l;
}
/* Mengirimkan list l dengan tambahan e sebagai elemen pertamanya. e dialokasi terlebih dahulu. 
   Jika alokasi gagal, mengirimkan l */
List konsb(List l, ElType e) {
    if (isEmpty(l)) {
        return konso(l, e);
    } else {
        NEXT(l) = konsb(NEXT(l), e);
        return l;
    }
}
/* Mengirimkan list l dengan tambahan e sebagai elemen terakhirnya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan l */ 
List copy(List l) {
    if (isEmpty(l)) {
        return NIL;
    } else {
        return konso(copy(tail(l)), head(l));
    }
}
/* Mengirimkan salinan list Ll (menjadi list baru) */
/* Jika ada alokasi gagal, mengirimkan l */ 
List concat(List l1, List l2) {
    if (isEmpty(l1)) {
        return l2;
    } else {
        return konso(concat(tail(l1), l2), head(l1));
    }
}
/* Mengirimkan salinan hasil konkatenasi list l1 dan l2 (menjadi list baru) */
/* Jika ada alokasi gagal, menghasilkan NIL */

/* Fungsi dan Prosedur Lain */
int length(List l) {
    if (isEmpty(l)) {
        return 0;
    } else {
        return 1 + length(tail(l));
    }
}
/* Mengirimkan banyaknya elemen list l, mengembalikan 0 jika l kosong */
boolean isMember(List l, ElType x) {
    if (isEmpty(l)) {
        return false;
    } else {
        return head(l) == x || isMember(tail(l), x);
    }
}
/* Mengirimkan true jika x adalah anggota list l dan false jika tidak */
void displayList(List l) {
    if (!isEmpty(l)) {
        printf("%d\n", head(l));
        displayList(tail(l));
    }
}
/* I.S. List l mungkin kosong */
/* F.S. Jika list tidak kosong, nilai list dicetak ke bawah */
/*      Dipisahkan dengan newline (\n) dan diakhiri dengan newline */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak:
  1
  20
  30
 */
/* Jika list kosong, tidak menuliskan apa-apa  */

/*** Tambahan primitif pemrosesan list ***/
List insertAt(List l, ElType e, int idx) {
    if (idx == 0) {
        return konso(l, e);
    } else {
        return konso(insertAt(tail(l), e, idx-1), head(l));
    }
}
/* Fungsi untuk menambahkan e sebagai elemen pada posisi/index idx sebuah list l */

List deleteFirst(List l) {
    if (l != NIL) return tail(l);
    return NIL;
}
/* Fungsi untuk menghapus elemen pertama sebuah list l */

List deleteAt(List l, int idx) {
    if (idx == 0) {
        return deleteFirst(l);
    } else {
        return konso(deleteAt(tail(l), idx-1), head(l));
    }
}
/* Fungsi untuk menghapus elemen pada posisi/index idx sebuah list l */

List deleteLast(List l) {
    if (isEmpty(l) || isOneElmt(l)) {
        return NIL;
    } else {
        return konso(deleteLast(tail(l)), head(l));
    }
}
/* Fungsi untuk menghapus elemen terakhir sebuah list l */

/*** Operasi-Operasi Lain ***/
List reverseList (List l) {
    if (isOneElmt(l) || isEmpty(l)) return l;
    else {
        return konsb(reverseList(tail(l)), head(l));
    }
}
/* Mengirimkan list baru, list l yang dibalik dengan menyalin semua elemen list.
Semua elemen list baru harus dialokasi */
/* Jika alokasi gagal, hasilnya list kosong */

void splitOddEven (List l, List *l1, List *l2) {
    if (!isEmpty(l)) {
        if (head(l)%2 == 0) {
            *l1 = konsb(*l1, head(l));
        } else {
            *l2 = konsb(*l2, head(l));
        }
        splitOddEven(tail(l), l1, l2);
    }
}
/* I.S. l mungkin kosong */
/* F.S. Berdasarkan l, dibentuk dua buah list l1 dan l2 */ 
/* l1 berisi semua elemen l yang genap, sedangkan l2 berisi
semua elemen l yang ganjil; semua dengan urutan yang sama seperti di l */
/* l tidak berubah: Semua elemen l1 dan l2 harus dialokasi */
/* Jika l kosong, maka l1 dan l2 kosong */

void splitOnX (List l, int x, List *l1, List *l2) {
    if (!isEmpty(l)) {
        if (x == 0) {
            *l2 = l;
        } else {
            *l1 = konsb(*l1, head(l));
            splitOnX(tail(l), x-1, l1, l2);
        }
    }
}
/* I.S. l dan x terdefinisi, l1 dan l2 sembarang. */
/* F.S. l1 berisi semua elemen l yang sebelum indeks ke-x 
      l2 berisi semua elemen l setelah indeks ke-x (termasuk indeks ke-x)
*/

ElType getMiddle(List l) {
    if(!isEmpty(l)) {
        int len = length(l);
        int mid = len/2;
        if (mid == 0) {
            return head(l);
        } else if (mid == 1) {
            return head(tail(l));
        } else {
            return getMiddle(tail(deleteLast(l)));
        }
    } else {
        return 0;
    }
    
}
/* I.S. l terdefinisi, mungkin kosong */
/* F.S. Mengembalikan elemen tengah dari List l */
/* Jika jumlah elemen dalam List l ganjil, elemen tengah adalah elemen yang berada di posisi tengah.
   Jika jumlah elemen dalam List l genap, elemen tengah adalah elemen di posisi tengah kedua. */
/* Contoh:
   l = [1, 2, 3, 4, 5]
   elemen tengah = 3

   l = [1, 6, 3, 10]
   elemen tengah = 3 (6 dan 3 berada di tengah, dikembalikan elemen tengah kedua, yaitu 3) */