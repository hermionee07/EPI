#include "utilities.h"
#include "primitiveTypes.h"
#include <iostream>
using namespace std;

int main()
{
    printBinary(65);
    cout << "Parity of 65 is " << calculateParity((unsigned long long) 65) << endl;
    printBinary(64);
    cout << "Parity of 64 is " << calculateParity((unsigned long long) 64) << endl;
    return 0;
}
