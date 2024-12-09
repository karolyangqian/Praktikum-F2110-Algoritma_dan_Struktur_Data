#include "stack.h"
#include <stdio.h>


void tambah(Stack *s) {
    int a = 0;
    int b = 0;
    int c;
    Pop(s, &a);
    Pop(s, &b);
    c = a + b;
    Push(s, b);
    Push(s, a);
    Push(s, c);
}

void sumAll(Stack *s) {
    int sum = 0;
    int x;
    while (!IsEmpty(*s)) {
        Pop(s, &x);
        sum += x;
    }
    Push(s, sum);
}

void avg(Stack *s) {
    int sum = 0;
    int x;
    int c = 0;
    while (!IsEmpty(*s)) {
        Pop(s, &x);
        sum += x;
        c++;
    }
    if (c > 0) {
        sum /= c;
    }
    Push(s, sum);
}

int chr2int(char c) {
    int a = c - '0';
    if (a >= 0 && a <= 9) return a;
    else return -1;
}

int main(int argc, char const *argv[])
{
    int N;
    Stack s;
    char c;
    int t;
    CreateEmpty(&s);
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf(" %c", &c);

        if (c == 'X') {
            Pop(&s, &t);
        } else if (c == '+') {
            tambah(&s);
        } else if (c == 'S') {
            sumAll(&s);
        } else if (c == 'A') {
            avg(&s);
        } else {
            Push(&s, c - '0');
        }
        // printf("%d", InfoTop(s));
        // for (int i = 0; i < N; i++)
        // {
        //     printf("%d", s.T[i]);
        // }
        // printf("\n");
    }
    sumAll(&s);
    int sum;
    Pop(&s, &sum);
    printf("%d\n", sum);
    
    return 0;
}
