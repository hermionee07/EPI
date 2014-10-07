#include "utilities.h"
#include "primitiveTypes.h"
#include <iostream>
#include <array>

using namespace std;

int main()
{
//    int i = -20;
//    if ( simpleParity(i) > 1)
//        cout << "simpleParity works only for unsigned integral values!" << endl;

    array<ushort, 65536> arr = {0};
    precomputeParity(arr);

    // input a huge number of 64 bit numbers, to find parities
    // of all these numbers.
    unsigned long long x = 34359738367;
    cout << "x = ";
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
