#ifndef PRIMITIVETYPES_H
#define PRIMITIVETYPES_H

#include <array>
#include <type_traits>

/*  This file contains solutions to questions related to primitive types in EPI */

//  5.1. Parity of a number 1 if the number of 1's in the number is odd, 0 if it is even
//  How to calculate the parities of a large number of 64 bit numbers.

//int simpleParity(unsigned long long x);

// Since XOR is associative, we can calculate the partity of all possible
// 16 bit numbers and store them. The 64 bit number itself can be divided into 4 16 bit numbers.
// It's parity can be calculated using this hashed information.

//unsigned short simpleParity(unsigned short x);

void precomputeParity(std::array<unsigned short, 65536>& arr);


template <typename T>
ushort simpleParity(T x)
{
    static_assert(std::is_integral<T>::value == true, "T should be integral");
    static_assert(std::is_unsigned<T>::value == true, "T should be unsigned");

    int result = 0;
    while (x)
    {
        result ^= (x & 1);
        x = x >> 1;
    }
    return result;
}

// 5.2 Bit swapping. Swap the ith bit with the jth bit in a 64 bit number

unsigned long long bitSwap(ushort i, ushort j, unsigned long long x);

// 5.2 Reverse the bits of a 64 bit integer in place.
//
unsigned long long reverseBits(unsigned long long x);

// 5.6 Implement string to int conversion functions and vice versa.
// Throws an invalid_argument exception if a bad argument is passed.
int stringToInt(const std::string& str);

std::string intToString(int x);

int GCD(int x, int y);

int GCDOptimized(int x, int y);
#endif //PRIMITIVETYPES_H
