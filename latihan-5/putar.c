#include "mesinkata.h"
#include <stdio.h>
int main(int argc, char const *argv[])
{
    STARTWORD();
    int c = 0;
    while (!EndWord)
    {
        if (c%2 == 0)
        {
            for (int i = 0; i < currentWord.Length/2; i++)
            {
                char temp = currentWord.TabWord[i];
                currentWord.TabWord[i] = currentWord.TabWord[currentWord.Length-1-i];
                currentWord.TabWord[currentWord.Length-1-i] = temp;
            }
        }
        for (int i = 0; i < currentWord.Length; i++)
        {
            printf("%c", currentWord.TabWord[i]);
        }
        ADVWORD();
        if (!EndWord) printf(" ");
        c++;
    }
    printf("\n");
    
    return 0;
}
