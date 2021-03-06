#include "primitiveTypes.h"
#include "utilities.h"
#include <array>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

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

unsigned long long bitSwap(ushort i, ushort j, unsigned long long x)
{
    // get the ith bit and the jth bit
    // if they are the same then we dont need to do anything.
    // if not ... XOR it with the number that has 1 in the jth and
    // ith bit positions.
    if (((x >> i) & 1) != ((x >> j) & 1)) // the bit values are different
    {
        x = x^((1ULL << i) | (1ULL << j));
    }
    return x;
}

unsigned long long reverseBits(unsigned long long x)
{
    // it is a 64bit number and we have to reverse all the 64 bits.
    for (ushort i = 0; i <= 31; i++)
    {
        x = bitSwap(i, 63-i, x);
    }
    return x;
}

int stringToInt(const std::string& str)
{
    std::vector<char> vec;

    //IsValidInt(str, vec);

    int num = 0, multiplier = 1;
    int len = vec.size();

    for(const char& a: vec) // finally got a good string to convert!
    {
        if (a == 45)
        {
            multiplier = -1;
            len--;
            continue;
        }
        if (a == 43)
        {
            multiplier = 1;
            len--;
            continue;
        }
        num = num + pow(10, len - 1) * ( a - 48);
        len--;
    }
    return num * multiplier;
}

std::string intToString(int x)
{
    bool negative = false;
    if (x < 0)
    {
        negative = true;
        x *= -1;
    }

    int remainder;
    vector<char> vec;
    while (x > 0) // O(number of digits)
    {
        remainder = x % 10;
        vec.push_back(48 + remainder);
        x = x / 10;
    }

    if (vec.empty())
        return "0";

    string result;

    reverse(vec.begin(), vec.end());

    if (negative)
    {
        result = result + "-";
    }

    for (const char& a: vec) // O(number of digits)
        result = result + a;

    return result;
}

int GCD(int x, int y)
{
    // Normal GCD
    // GCD(x, y) == GCD(max(x,y)-min(x,y), min(x,y))
    if (x == y)
        return x;
    else
        return GCD(abs(x-y), min(x,y));
}

int GCDOptimized(int x, int y)
{
    if (x == y)
        return x;
    else if (((x & 1) == 0) && ((y & 1) == 0))  // both are even
        return (GCDOptimized(x>>1, y>>1) << 1); // get the GCD of x/2 and y/2 and multiply it by 2.
    else                                        // one of them is odd
        return GCD(abs(x-y), min(x,y));
}





