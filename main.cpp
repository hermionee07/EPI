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
    cout << ".................................." << endl;
    x = 15;
    printBinary(x);
    x = bitSwap(0,63,x);
    printBinary(x);
    printBinary(5);
    x = reverseBits(5);
    printBinary(x);
    try
    {
        int b = stringToInt("+0");
        int c = stringToInt("+2478");
        cout << "b is" << b << " c is " << c << endl;
    }
    catch(const std::invalid_argument& e)
    {
        cout <<e.what() << endl;
    }
    cout << intToString(0) << endl;
    cout << intToString(-5-67) << endl;
    cout << "GCD of 45, 80 is " << GCD(45,80) <<endl;
    cout << "GCD of 45, 61 is " << GCD(45,61) <<endl;

    cout << "GCD of 4, 80 is " << GCDOptimized(4,80) <<endl;
    cout << "GCD of 45, 60 is " << GCDOptimized(45,60) <<endl;
    cout << "GCD of 45, 7 is " << GCDOptimized(45,7) <<endl;

    return 0;
}
