#include "stack.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    Stack s;
    CreateEmpty(&s);
    int N;
    scanf("%d", &N);

    if (N%2 != 0) {
        printf("Invalid\n");
    } else {
        boolean benar = true;
        for (int i = 0; i < N; i++) {
            char c;
            scanf(" %c", &c);
            if ( c == '(' || c == '{' ||  c == '[') {
                Push(&s, c);
            } else {
                boolean a = c == ')' && InfoTop(s) == '(';
                boolean b = c == '}' && InfoTop(s) == '{';
                boolean k = c == ']' && InfoTop(s) == '[';
                if (!(a || b || k)) {
                    benar = false;
                    break;
                } else {
                    char t;
                    Pop(&s, &t);
                }
            }
        }

        if (benar && IsEmpty(s)) {
            printf("Valid\n");
        } else {
            printf("Invalid\n");
        }
    }

    return 0;
}
