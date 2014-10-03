#include "utilities.h"
#include "primitiveTypes.h"
#include <iostream>
#include <array>

using namespace std;

int main()
{
//    printBinary(65);
//    cout << "Parity of 65 is " << calculateParity((unsigned long long) 65) << endl;
//    printBinary(64);
//    cout << "Parity of 64 is " << calculateParity((unsigned long long) 64) << endl;

    array<ushort, 65536> arr = {0};
    precomputeParity(arr);

    // input a huge number of 64 bit numbers, to find parities
    // of all these numbers.
    unsigned long long x = 34359738367;
    printBinary(x);
    ushort one = arr[x & ((1 << 16) - 1)];
    x = x >> 16;
    ushort two = arr[x & ((1 << 16) - 1)];
    x = x >> 16;
    ushort three = arr[x & ((1 << 16) - 1)];
    x = x >> 16;
    ushort four = arr[x];
    ushort  p = one^two^three^four;
    cout << "Parity of x is " << p << endl;

    return 0;
}
