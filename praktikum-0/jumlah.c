#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n, k, i, a_i;
    int s = 0;
    scanf("%d %d", &n, &k);
    for ( i = 0; i < n; i++)
    {
        scanf("%d", &a_i);
        if (a_i%k != 0)
        {
            s = s + a_i;
        }
        
    }
    printf("%d\n", s);
    return 0;
}
