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

    array<unsigned short, 65536> arr = {0};
    precomputeParity(arr);

    // input a huge number of 64 bit numbers, to find parities
    // of all these numbers.
    unsigned long long x = 34359738367;
    printBinary(x);
    unsigned short one = arr[x & ((1 << 16) - 1)];
    x = x >> 16;
    unsigned short two = arr[x & ((1 << 16) - 1)];
    x = x >> 16;
    unsigned short three = arr[x & ((1 << 16) - 1)];
    x = x >> 16;
    unsigned short four = arr[x];
    unsigned short  p = one^two^three^four;
    cout << "Parity of x is " << p << endl;

    return 0;
}
