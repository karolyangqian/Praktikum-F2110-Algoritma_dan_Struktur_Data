#include "liststatik.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    ListStatik inputArray, set, count;
    CreateListStatik(&inputArray); CreateListStatik(&set); CreateListStatik(&count);
    readList(&inputArray);

    for (int i = 0; i < listLength(inputArray); i++) {
        // jika tidak ada di set
        if (indexOf(set, ELMT(inputArray, i)) == IDX_UNDEF) {
            insertLast(&set, ELMT(inputArray, i));
            insertLast(&count, 1);
        }
        else {
            ELMT(count, indexOf(set, ELMT(inputArray, i)))++;
        }
    }



    printList(set);
    printf("\n");
    for (int i = 0; i < listLength(count); i++)
    {
        printf("%d %d\n", ELMT(set, i), ELMT(count, i));
    }
    
    return 0;
}
