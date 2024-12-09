#include "listrec.h"

int main() {
    List l = NULL;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        l = konsb(l, x);
    }
    displayList(l);
    printf("%d", getMiddle(l));
}