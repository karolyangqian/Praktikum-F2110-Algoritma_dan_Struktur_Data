#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int i, j, k;
    for (i = n; i > 0; i--)
    {
        for ( k = 0; k < (n-i); k++)
        {
            printf(" ");
        }
        for ( j = 0; j < (2*i-1); j++)
        {
            
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
