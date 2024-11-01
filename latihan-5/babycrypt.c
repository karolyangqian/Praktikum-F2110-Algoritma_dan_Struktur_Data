#include "mesinkata.h"
#include <stdio.h>

char decrypt(char c, int n) {
    int a = c;
    if ((c >= 'a' && c <= 'z') || (a >='A' && a <= 'Z'))
    {
        a = c - n%26;
        if ((a < 'a' && c >= 'a') || (a < 'A' && c >= 'A'))
        {
            a += 26;
        }
    }
    return a;
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    // printf("%c", decrypt('B', n));
    // printf("%d %d", decrypt('!', n), '!');
    STARTWORD();
    while (!EndWord)
    {
        Word d  = currentWord;
        for (int i = 0; i < currentWord.Length; i++)
        {
            d.TabWord[i] = decrypt(currentWord.TabWord[i], n);
        }
        for (int i = 0; i < d.Length; i++)
        {
            printf("%c", d.TabWord[i]);
        }
        ADVWORD();
        if (!EndWord)
        {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}
