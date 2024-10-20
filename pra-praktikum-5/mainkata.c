#include <stdio.h>
#include "mesinkata.h"

int main(int argc, char const *argv[])
{
    STARTWORD();
    while (!EndWord) {
        for (int i = 0; i < currentWord.Length; i++) {
            printf("%c", currentWord.TabWord[i]);
        }
        printf("\n");
        ADVWORD();
    }
    return 0;
}