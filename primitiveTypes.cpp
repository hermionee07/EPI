#include "primitiveTypes.h"
#include "utilities.h"
#include <array>
#include <iostream>
#include <vector>
#include <math.h>

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

    int i = 0;
    for (char c : str)
    {
        if ((c == 45 && i == 0) || (c > 47 && c < 58))
        {
            vec.push_back(c);
        }
        else
            throw std::invalid_argument( "Received a bad argument");
        i++;
    }

    int num = 0, multiplier = 1;
    if (vec.size() == 1 && (*vec.begin()) == 45)
        throw std::invalid_argument( "Received a bad argument");
    int len = vec.size();
    for(char& a: vec)
    {
        if (a == 45)
        {
            multiplier = -1;
            len--;
        }
        for (int i = 48; i < 58; i++)
        {
            if (len != 0 && a == i)
            {
                num = num + pow(10, len - 1) * (i - 48);
                len--;
            }
        }
    }
    return num * multiplier;
}












