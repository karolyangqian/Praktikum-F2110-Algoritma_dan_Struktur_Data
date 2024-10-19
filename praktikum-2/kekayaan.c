#include "liststatik.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    ListStatik uang;
    CreateListStatik(&uang);
    readList(&uang);

    ELMT(uang, listLength(uang)-1) += 1;

    int i = listLength(uang) - 1;

    while (i > 0 && ELMT(uang, i) > 9) {
        ELMT(uang, i) %= 10;
        ELMT(uang, i-1) += 1;
        i--;
    }
    if (ELMT(uang, 0) > 9) {
        ELMT(uang, 0) %= 10;
        insertFirst(&uang, 1);
    }

    for (int i = 0; i < listLength(uang); i++)
    {
        printf("%d", ELMT(uang, i));
        if (i < listLength(uang)-1) printf(" ");
    }
    printf("\n");
    
    return 0;
}
