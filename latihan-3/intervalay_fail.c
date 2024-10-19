#include "listdin.h"
#include <stdio.h>

// void insertAt(ListDin *l, int idx, int val) {
//     for (int i = listLength(*l) - 1; i >= idx; i--)
//     {
//         ELMT(*l, i + 1) = ELMT(*l, i);
//     }
//     ELMT(*l, idx) = val;
//     NEFF(*l)++;
// }

boolean checkIntersect(int L1, int R1, int L2, int R2) {
    return (L2 <= R1 && L1 <= R2) || (L1 <= R2 && L2 <= R1);
}


int main() {
    ListDin intervalay, newArray;
    CreateListDin(&intervalay, 1000);
    CreateListDin(&newArray, 1000+2);
    readList(&intervalay);
    int unionStart, unionEnd;
    scanf("%d %d", &unionStart, &unionEnd);

    if (listLength(intervalay) == 0) {
        insertLast(&newArray, unionStart);
        insertLast(&newArray, unionEnd);
    } else {
        int i = 0;
        while (i < listLength(intervalay)) {
            while (checkIntersect(ELMT(intervalay, i), ELMT(intervalay, i+1), unionStart, unionEnd)) {
                unionStart = unionStart < ELMT(intervalay, i) ? unionStart : ELMT(intervalay, i);
                unionEnd = unionEnd > ELMT(intervalay, i+1) ? unionEnd : ELMT(intervalay, i+1);
                i += 2;
                if (!checkIntersect(ELMT(intervalay, i), ELMT(intervalay, i+1), unionStart, unionEnd)) {
                    insertLast(&newArray, unionStart);
                    insertLast(&newArray, unionEnd);
                    break;
                }
            } 
            insertLast(&newArray, ELMT(intervalay, i));
            insertLast(&newArray, ELMT(intervalay, i+1));
            
            i += 2;
        }
    }


    // printList(newArray);
    for (int i = 0; i < listLength(newArray); i++) {
        printf("%d", ELMT(newArray, i));
        if (i != listLength(newArray)-1) printf(" ");
    }
    printf("\n");
    dealocateList(&intervalay);
    dealocateList(&newArray);
    return 0;
}