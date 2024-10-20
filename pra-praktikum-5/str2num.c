#include "mesinkata.h"
#include <stdio.h>
#include <string.h>

#define NOT_FOUND -1

typedef struct {
    Word word;
    int value;
} MapAngkaKata;

MapAngkaKata angkaKata[37] = {
    { .word = {"nol", 3}, .value = 0 },
    { .word = {"satu", 4}, .value = 1 },
    { .word = {"dua", 3}, .value = 2 },
    { .word = {"tiga", 4}, .value = 3 },
    { .word = {"empat", 5}, .value = 4 },
    { .word = {"lima", 4}, .value = 5 },
    { .word = {"enam", 4}, .value = 6 },
    { .word = {"tujuh", 5}, .value = 7 },
    { .word = {"delapan", 7}, .value = 8 },
    { .word = {"sembilan", 8}, .value = 9 },
    { .word = {"sepuluh", 7}, .value = 10 },
    { .word = {"sebelas", 7}, .value = 11 },
    { .word = {"dua belas", 9}, .value = 12 },
    { .word = {"tiga belas", 10}, .value = 13 },
    { .word = {"empat belas", 11}, .value = 14 },
    { .word = {"lima belas", 10}, .value = 15 },
    { .word = {"enam belas", 10}, .value = 16 },
    { .word = {"tujuh belas", 11}, .value = 17 },
    { .word = {"delapan belas", 13}, .value = 18 },
    { .word = {"sembilan belas", 14}, .value = 19 },
    { .word = {"dua puluh", 9}, .value = 20 },
    { .word = {"tiga puluh", 10}, .value = 30 },
    { .word = {"empat puluh", 11}, .value = 40 },
    { .word = {"lima puluh", 10}, .value = 50 },
    { .word = {"enam puluh", 10}, .value = 60 },
    { .word = {"tujuh puluh", 11}, .value = 70 },
    { .word = {"delapan puluh", 13}, .value = 80 },
    { .word = {"sembilan puluh", 14}, .value = 90 },
    { .word = {"seratus", 7}, .value = 100 },
    { .word = {"dua ratus", 9}, .value = 200 },
    { .word = {"tiga ratus", 10}, .value = 300 },
    { .word = {"empat ratus", 11}, .value = 400 },
    { .word = {"lima ratus",10}, .value = 500 },
    { .word = {"enam ratus", 10}, .value = 600 },
    { .word = {"tujuh ratus", 11}, .value = 700 },
    { .word = {"delapan ratus", 13}, .value = 800 },
    { .word = {"sembilan ratus", 14}, .value = 900 }
};

boolean wordcmp(Word w1, Word w2) {
    if (w1.Length != w2.Length) return false;
    else {
        for (int i = 0; i < w1.Length; i++)
        {
            if (w1.TabWord[i] != w2.TabWord[i]) return false;
        }
        return true;        
    }
}

int wordValue(Word w) {
    int i = 0;
    while (i < sizeof(angkaKata) / sizeof(MapAngkaKata) && !wordcmp(w, angkaKata[i].word)) {
        i++;
    }
    if (i == sizeof(angkaKata) / sizeof(MapAngkaKata)) return NOT_FOUND;
    else return angkaKata[i].value;
}

void make2Words(Word w1, Word w2, Word *w3) {
    int i = 0;
    for (int j = 0; j < w1.Length; j++)
    {
        w3->TabWord[i] = w1.TabWord[j];
        i++;
    }
    w3->TabWord[i] = ' ';
    i++;
    for (int j = 0; j < w2.Length; j++)
    {
        w3->TabWord[i] = w2.TabWord[j];
        i++;
    }
    w3->Length = i;
}

void printWord(Word w) {
    for (int i = 0; i < w.Length; i++)
    {
        printf("%c", w.TabWord[i]);
    }
}

int tens(int a) {
    if (a >= 1000) return 1000;
    if (a >= 100) return 100;
    if (a >= 10 ) return 10;
    else return 0;
}

int main() {
    Word w1, w2, w3;
    int tot = 0;
    int a = 10000;
    int b = 0;
    
    STARTWORD();
    w2 = currentWord;
    while (!EndWord) {
        w1 = w2;
        ADVWORD();
        w2 = currentWord;
        make2Words(w1, w2, &w3);
        // printf("{");
        // printWord(w3);
        // printf("}\n");
        if (wordValue(w3) != NOT_FOUND) {
            b = wordValue(w3);
            ADVWORD();
            w2 = currentWord;
        } else if (wordValue(w1) != NOT_FOUND) {
            b = wordValue(w1);
        } else {
            b = NOT_FOUND;
        }

        if (b != NOT_FOUND && b < tens(a)) {
            tot += b;
            a = b;
        } else {
            if (a != 10000) {
                printf("%d", tot);
                printf(" ");
                if (b == NOT_FOUND)
                {
                    printWord(w1);
                    if (!EndWord) printf(" ");
                }
                
            }
            else {
                printWord(w1);
                if (!EndWord) printf(" ");
            } 

            if (b != NOT_FOUND) {
                tot = b;
                a = b;
            } else {
                
                tot = 0;
                a = 10000;
            }
        }

        

        // // printWord(w1);
        // // printf("\n");
        // if ((a < b || b <= 0) && a != 10000) {
        //     printf("%d", tot);
        //     tot = 0;
        //     a = 10000;
        // }
        // if (!EndWord) printf(" ");
        // if (b == NOT_FOUND) a = 10000;
        // else { 
        //     a = b;
        // }
    }


    if (wordValue(w3) != NOT_FOUND) {
        printf("%d", tot);
    } else if (wordValue(w1) != NOT_FOUND) {
        printf("%d", tot);
    }

    printf("\n");
    return 0;
}