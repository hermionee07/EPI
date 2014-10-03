#include "primitiveTypes.h"
#include "utilities.h"
#include <array>
#include <iostream>

using namespace std;

/*int simpleParity(unsigned long long x)
{
    int result = 0;
    while (x)
    {
        result ^= (x & 1);
        x = x >> 1;
    }
    return result;
}*/

ushort simpleParity(ushort x)
{
    ushort result = 0;
    while (x)
    {
        result ^= (x & 1);
        x = x >> 1;
    }
    return result;
}

void precomputeParity(std::array<ushort, 65536>& arr)
{
    // from 0 to 65535, calculate partity and store it in an array
    // arr[0] = 0; because parity of zero is 0.
    for (int i =0; i <= 65535; i++)
    {
        arr[i] = simpleParity(i);
    }
    return;
}

