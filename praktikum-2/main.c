#include "liststatik.h"
#include <stdio.h>

/*
1. ada terbanyak kedua, satu atau lebih
2. tidak ada elemen terbanyak kedua, karena sama2 terbanyak atau array homogen
*/

// Menghapus elemen terbanyak dan mengembalikan list tanpa elemen tsb
// val adalah elemen tsb
ListStatik mostFrequent(ListStatik l, int *val, int *valCount) {
    ListStatik set, count;
    CreateListStatik(&set); CreateListStatik(&count);

    if (listLength(l) == 0) {
        *val = -1;
        *valCount = 0;
        ListStatik empty;
        CreateListStatik(&empty);
        return empty;
    }
    else {
        for (int i = 0; i < listLength(l); i++) {
            // jika tidak ada di set
            if (indexOf(set, ELMT(l, i)) == IDX_UNDEF) {
                insertLast(&set, ELMT(l, i));
                insertLast(&count, 1);
            }
            else {
                ELMT(count, indexOf(set, ELMT(l, i)))++;
            }
        }

        int mostFreqCount, min;
        extremeValues(count, &mostFreqCount, &min);

        *val = ELMT(set, indexOf(count, mostFreqCount));
        *valCount = mostFreqCount;
        while (indexOf(l, *val) != IDX_UNDEF) {
            int dump;
            deleteAt(&l, &dump, indexOf(l, *val));
        }
        return l;
    }
}

int main(int argc, char const *argv[])
{
    ListStatik l;
    CreateListStatik(&l);
    readList(&l);
    sortList(&l, true);

    ListStatik newL;
    int val, first, second;
    newL = mostFrequent(l, &val, &first);
    second = first;

    while (listLength(newL) != 0 && first == second) {
        newL = mostFrequent(newL, &val, &second);
    }

    if (first == second) {
        printf("Tidak ada elemen kedua yang paling sering muncul\n");
    }
    else {
        printf("%d\n", val);
    }

    
    return 0;
}

// tidak ada: 2 5 6
// ??: 4 7