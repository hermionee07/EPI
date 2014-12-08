#ifndef UTILITIES_H

#define UTILITIES_H

#include <vector>
#include <string>
#include <algorithm> // this should be removed.
void printBinary(unsigned long long x);
typedef unsigned short ushort;

//int IsValidInt(const std::string& a, std::vector<char>& vec);
//int IsValidInt1(const std::string& a);
template <typename T>
bool IsValidInt1(const T& str)
{
    int i = 0;
    typename T::const_iterator c;
    for (c = str.begin(); c != str.end(); c++)
    {
        if (((*c == 45 || *c == 43) && i == 0) || (*c > 47 && *c < 58))
            i++;
        else
            throw std::invalid_argument( "Received a bad argument"); // string has non-numeral char
    }

    int len = i;

    if (len == 1 && ((*str.begin()) == 45 || (*str.begin()) == 43)) // got a string with a +/- sign and no number!
        throw std::invalid_argument( "Received a bad argument");

    if (len == 0) // got an empty string!
        throw std::invalid_argument( "Received a bad argument");

    return true;
}

#endif // UTILITIES_H
