#include "primitiveTypes.h"
#include "utilities.h"

int calculateParity(unsigned long long x)
{
    int result = 0;
    while (x)
    {
        result ^= (x & 1);
        x = x >> 1;
    }
    return result;
}

