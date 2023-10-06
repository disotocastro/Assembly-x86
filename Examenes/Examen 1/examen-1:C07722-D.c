#include <stdio.h>

int LowerOneMask(int n)
{   int mask = (2 << (n - 1)) - 1;
    
    return mask&n;
}