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
    if (std::is_integral<T>::value == true && std::is_unsigned<T>::value == true)
    {
        int result = 0;
        while (x)
        {
            result ^= (x & 1);
            x = x >> 1;
        }
        return result;
    }
    else
        return 2;
    // this needs to be clever to return a good error!
}


#endif //PRIMITIVETYPES_H
