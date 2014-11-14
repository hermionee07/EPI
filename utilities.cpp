#include <iostream>
#include <string>
#include "utilities.h"
#include <algorithm>

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

//int IsValidInt(const std::string& str, std::vector<char>& vec)
//{
//    int i = 0;
//    for (const char& c : str)
//    {
//        if (((c == 45 || c == 43) && i == 0) || (c > 47 && c < 58))
//        {
//            vec.push_back(c);
//        }
//        else
//            throw std::invalid_argument( "Received a bad argument"); // string has non-numeral char
//        i++;
//    }
//
//    int len = vec.size();
//
//    if (len == 1 && ((*vec.begin()) == 45 || (*vec.begin()) == 43)) // got a string with a +/- sign and no number!
//        throw std::invalid_argument( "Received a bad argument");
//
//    if (len == 0) // got an empty string!
//        throw std::invalid_argument( "Received a bad argument");
//}

//template <typename T>
//int IsValidInt1(const T& str)
//{
//    int i = 0;
//    typename T::const_iterator c;// = str.begin();
//    for (c = str.begin(); c != str.end(); c++)
//  //for (const char& c : str)
//    {
//        if (((*c == 45 || *c == 43) && i == 0) || (*c > 47 && *c < 58))
//            i++;
//        else
//            throw std::invalid_argument( "Received a bad argument"); // string has non-numeral char
//    }
//
//    int len = i;
//
//   if (len == 1 && ((*str.begin()) == 45 || (*str.begin()) == 43)) // got a string with a +/- sign and no number!
//        throw std::invalid_argument( "Received a bad argument");
//
//    if (len == 0) // got an empty string!
//        throw std::invalid_argument( "Received a bad argument");
//
//   return 1;
//}
