#include <stdio.h>
#include "boolean.h"
#include "stack.h"
#include <math.h>

void printStack(Stack s) {
    char t;
    int n = Top(s);
    for (int i = 0; i <= n; i++) {
        // Pop(&s, &t);
        printf("%c", s.T[i]);
    }
}

int powi(int base, int pow) {
    int res = 1;
    for (int i = 0; i < pow; i++) {
        res *= base;
    }
    return res;
}

void pushKStackRev(Stack *s, int k, Stack t) {
    int n = Top(t);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j <= Top(t); j++) {
            Push(s, t.T[n-j]);
        }
    }
}

int main()
{
    int N, i, k, j;
    char ch, t;

    // Stack declaration here
    Stack mainS, nestedS, tempS;
    CreateEmpty(&mainS);
    CreateEmpty(&nestedS);
    CreateEmpty(&tempS);

    scanf("%d\n", &N);

    // Start code here
    for (i = 0; i < N; i++) {
        scanf(" %c", &ch);

        // Semua karakter dipush* ke mainS (mainStack) sampai ketemu ']'**
        if (ch == ']') {
            // kalau ketemu ']', pop satu2 karakter di mainS lalu push ke nestedS (nestedStack) sampai ketemu '[' 
            CreateEmpty(&nestedS);
            while (InfoTop(mainS) != '[') {
                Pop(&mainS, &t);
                Push(&nestedS, t);
            }
            Pop(&mainS, &t); // skip '[' pada mainS
            k = 0;
            j = 0;
            // parsing angka yang ada di bawah '[' di mainS lalu simpan ke k
            while (InfoTop(mainS) >= '0' && InfoTop(mainS) <= '9') {
                Pop(&mainS, &t);
                k += (t - '0')*powi(10, j);
                j++;
            } // F.S. InfoTop(mainS) adalah char sebelum angka

            // kumpulan char yang ada di nestedS dipush ke mainS sebanyak k kali
            pushKStackRev(&mainS, k, nestedS);
        } else {
            // *ini push karakter ke mainStack-nya
            Push(&mainS, ch);
        }

        // Setelah sequence di atas selesai, scanf(" %c", &ch) di awal loop akan merujuk ke char setelah **']'. 
        // Jika ada nested encoded e.g. 3[a2[hmif]], ini akan kehanddle karena setelah sequense di atas selesai sekali,
        // isi mainS akan menjadi 3[ahmifhmif dan sequence di atas dapat mengatasinya lagi.
    }
    printStack(mainS);
    printf("\n");

    return 0;
}