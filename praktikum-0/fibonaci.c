#include <stdio.h>

int f(int n, int a, int b) {
    if (n == 1)
    {
        return a;
    }
    else if (n == 2)
    {
        return b;
    }
    
    else if (n > 2)    
    {
        return f(n-1, a, b) + f(n-2, a, b);
    }
    
}

int main(int argc, char const *argv[])
{
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    printf("%d\n", f(n, a, b));    
    return 0;
}
