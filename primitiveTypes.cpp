#include "primitiveTypes.h"
#include "utilities.h"
#include <array>
#include <iostream>

using namespace std;

void precomputeParity(std::array<ushort, 65536>& arr)
{
    // from 0 to 65535, calculate partity and store it in an array
    // arr[0] = 0; because parity of zero is 0.
    for (unsigned int i =0; i <= 65535; i++)
    {
        arr[i] = simpleParity(i);
    }
    return;
}

