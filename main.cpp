#include "utilities.h"
#include "primitiveTypes.h"
#include "arraysAndStrings.h"
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
        int b = IsValidInt1(std::string("+0"));
        int c = IsValidInt1(std::string("+2478"));
        cout << "b is " << b << " c is " << c << endl;
        int d = IsValidInt1(std::string("-56-"));
    }
    catch(const std::invalid_argument& e)
    {
        cout << e.what() << endl;
    }
    char a = 53;
    cout << a << endl;
    int t = -90;
    printf("--- %b --\n ", t);

    cout << "GCD of 5 and 7: " << GCD(5, 7) << endl;
    cout << "GCD of 5 and 7: " << GCDOptimized(5, 7) << endl;
    cout << "GCD of 35 and 60: " << GCD(35, 60) << endl;
    cout << "GCD of 35 and 60: " << GCDOptimized(35, 60) << endl;
    cout << "GCD of 45 and 90: " << GCD(45, 90) << endl;
    cout << "GCD of 45 and 90: " << GCDOptimized(45, 90) << endl;
    cout << "GCD of 3 and 9: " << GCD(3, 9) << endl;
    cout << "GCD of 3 and 9: " << GCDOptimized(3, 9) << endl;
    BigNumberMultiplication("456", "222");
    return 0;
}
