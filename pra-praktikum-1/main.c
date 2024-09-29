#include <stdio.h>
#include "point.h"

int main()
{
    POINT p;
    CreatePoint(&p, 2, 3);
    TulisPOINT(p);
    return 0;
}