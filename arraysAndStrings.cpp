#include "arraysAndStrings.h"
#include "utilities.h"
#include "primitiveTypes.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <array>

std::string BigNumberMultiplication(const std::string& a1, 
        const std::string& b1)
{
    if (IsValidInt1(a1) && IsValidInt1(b1))
    {
        std::string sign = "+";
        std::string a, b;

        // when both of them have a different signs.
        if (((*a1.begin()) == 45 && (*b1.begin()) == 43) || 
            ((*a1.begin()) == 43 && (*b1.begin()) == 45) )
        {
            sign = "-";
            a = std::string(a1.begin()+1, a1.end());
            b = std::string(b1.begin()+1, b1.end());
        }
        // when both of them have the same sign
        else if  (((*a1.begin()) == 43 && (*b1.begin()) == 43) ||
                 ((*a1.begin()) == 45 && (*b1.begin()) == 45) )
        {
            sign = "+";
            a = std::string(a1.begin()+1, a1.end());
            b = std::string(b1.begin()+1, b1.end());
        }
        // when one of them has a sign        
        else if  (((*a1.begin()) == 43 || (*b1.begin()) == 43) ||
                 ((*a1.begin()) == 45 || (*b1.begin()) == 45) )
        {
            if ((*b1.begin())== 43 || (*b1.begin()) == 45)
            {
                if (*b1.begin() == 45)
                    sign = "-";
                b = std::string(b1.begin()+1, b1.end());
                a = std::string(a1.begin(), a1.end());
            }
            else
            {
                if (*a1.begin() == 45)
                    sign = "-";
                b = std::string(b1.begin(), b1.end());
                a = std::string(a1.begin()+1, a1.end());
            }
        } 
        else // When non of them has a sign
        {
            a = std::string(a1.begin(), a1.end());
            b = std::string(b1.begin(), b1.end());
        }

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        if (!a.empty() && !b.empty())
        {
            int zeroesToAdd = 0;
            std::string number (a.length() + b.length(), '0');
            
            for (std::string::const_iterator multiplier = b.begin(); 
                    multiplier != b.end(); multiplier++)
            {
                short carryOver = 0;
                std::string row;
                for (int k = 0; k != zeroesToAdd; k++)
                    row = row + "0";

                for(std::string::const_iterator itr = a.begin(); 
                        itr != a.end(); itr++)
                {
                    short i = (((*itr) - 48) * ((*multiplier)- 48)) + carryOver;
                    if (i >= 10)
                    {
                        short j  = i % 10;
                        carryOver = i/10;
                        row = row + intToString(j);
                    }
                    else
                    {
                        row = row + intToString(i);
                        carryOver = 0;
                    }
                }
                
                row = row + intToString(carryOver);
                carryOver = 0;
                for (int z = 0; z < row.length(); z++)
                {
                    short i = number[z];
                    short j;
                    if (i != 0)
                    {
                        j = (row[z] - 48) + (i - 48) + carryOver; 
                    }
                    else
                    {
                        j = (row[z] - 48) + i + carryOver; 
                    }
                    if (j >=10)
                    {
                        short k = j % 10;
                        carryOver = j / 10;
                        number[z] = k + 48;
                    }
                    else
                    {
                        carryOver = 0;
                        number[z] = j + 48;
                    }
                }
                zeroesToAdd++;
            }
            reverse(number.begin(), number.end());
            return sign + number;
        }
    }
    return "";
}

