#include "hapus-duplikat.h"
#include <stdlib.h>

List hapusDuplikat(List l) {
    Address p = FIRST(l), next, prev = NULL;
    ElType del;

    if (length(l) <= 1) return l;

    while (p != NULL) {
        if (NEXT(p) != NULL && INFO(NEXT(p)) == INFO(p)) {
            del = INFO(p);
            while (p != NULL && INFO(p) == del) {
                if (p == FIRST(l)) {
                    p = NEXT(p);
                    deleteFirst(&l, &del);
                } else {
                    NEXT(prev) = NEXT(p);
                    free(p);
                    p = NEXT(prev);
                }

            }
        } else {
            prev = p;
            p = NEXT(p);
        }
    }

    p = FIRST(l);
    prev = NULL;
    next = p;
    while (p != NULL) {
        next = NEXT(next);
        NEXT(p) = prev;
        prev = p;
        p = next;
    }

    FIRST(l) = prev;

    return l;
}
/**
 * Menerima masukan sebuah list l yang terurut mengecil
 * Mengembalikan list yang merupakan hasil penghapusan elemen yang mempunyai duplikat pada list l, terurut membesar
 * Contoh: hapusDuplikat(3->3->2->1) = 1->2 (-> adalah panah next pada list linear)
 */

// int main () {
//     List l;
//     CreateList(&l);
//     insertLast(&l, 1);
//     insertLast(&l, 2);
//     insertLast(&l, 2);
//     // insertLast(&l, 3);
//     l = hapusDuplikat(l);
//     displayList(l);
//     return 0;
// }