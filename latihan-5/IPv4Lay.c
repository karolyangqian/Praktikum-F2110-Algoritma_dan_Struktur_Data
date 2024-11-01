#include "mesinkata.h"
#include <stdio.h>

int powc(int a, int b) {
    int c = 1;
    for (int i = 0; i < b; i++)
    {
        c *= a;
    }
    return c;
}

// tidak termasuk end
int str2int(char *s, int start, int end) {
    int res = 0;
    for (int i = 0; i < end-start; i++)
    {
        if (s[start+i] - '0' < 0 || s[start+i] - '0' > 9) return -1;
        res += (s[start+i] - '0') * powc(10, (end-start)-1-i);
    }
    return res;
}


int main(int argc, char const *argv[])
{
    int acount, numcount, sublen;
    boolean subvalid;
    STARTWORD();
    while (!EndWord) {
        acount = 0;
        numcount = 0;
        sublen = 0;
        subvalid = true;
        
        for (int i = 0; i <= currentWord.Length; i++) {
            if ( i == currentWord.Length || currentWord.TabWord[i] == '@') {
                // printf("%d\n", sublen);
                if (i != currentWord.Length && currentWord.TabWord[i] == '@') acount++;

                if (currentWord.TabWord[i-sublen] != '0' || (currentWord.TabWord[i-sublen] == '0' && sublen == 1)) {
                    int val;
                    if (sublen != 0) {
                        // if (i == currentWord.Length && currentWord.TabWord[i] != '@') val = str2int(currentWord.TabWord, i-sublen, i);
                        val = str2int(currentWord.TabWord, i-sublen, i);
                    } else {
                        subvalid = false;
                        break;
                    }

                    // printf("%d\n", val);
                    if (val == -1) {
                        subvalid = false;
                        break;
                    }

                    if (val >= 0 && val <= 255) {
                        numcount++;
                    } else {
                        subvalid = false;
                        break;
                    }
                } else {
                    subvalid = false;
                    break;
                } 
                
                sublen = 0;
                

            } else {
                sublen++;
            }

            if (acount > 3 || numcount > 4) {
                subvalid = false;
                break;
            }
        }

        if (subvalid && acount == 3 && numcount == 4) {
            // printf("%d %d\n", acount, numcount);
            printf("4Lay");
        } else {
            printf("ewh");
        }

        ADVWORD();
        if (!EndWord) printf (" ");
    }
    printf("\n");
    return 0;
}

/*
35@135@23@23
   i-   i
*/