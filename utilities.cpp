#include <iostream>
#include <string>
#include "utilities.h"

using namespace std;

void printBinary(unsigned long long x)
{
    int i = 0, j = 64;
    string str;
    while(j)
    {
        i = x & 1;
        str = str + to_string(i);
        x = x >> 1;
        j--;
    }
    for (std::string::reverse_iterator rit=str.rbegin();
        rit!=str.rend(); ++rit)
            std::cout << *rit;
    cout << endl;
}


