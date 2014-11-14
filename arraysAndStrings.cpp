#include "arraysAndStrings.h"
#include "utilities.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <array>

std::string BigNumberMultiplication(const std::string& a, const std::string& b)
{
    std::vector<char> num1, num2;
    if (IsValidInt1(a) && IsValidInt1(b))
    {
    int multiplier = 1;

    std::map<int, std::vector<short>> rows;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
 //   if (*(num1.begin())!= *(num2.begin()))
 //   {
 //       multiplier = -1;
 //       num1.pop();
 //       num2.pop();
 //   }

    if (!num1.empty() && !num2.empty())
    {
        short carryOver = 0;
        int zeroToAdd = 0;
        short number[] = {0};
        for (std::vector<char>::const_iterator multiplier = num2.begin(); multiplier != num2.end(); multiplier++)
        {
            std::vector<short> row;
            for (int k = 0; k != zeroToAdd; k++)
                row.push_back(0);

            for(std::vector<char>::const_iterator itr = num1.begin(); itr != num1.end(); itr++)
            {
                short i = (((*itr) - 48) * ((*multiplier)- 48)) + carryOver;
                if (i >= 10)
                {
                    short j  = i % 10;
                    carryOver = i/10;
                    row.push_back(j);
                }
                else
                {
                    row.push_back(i);
                    carryOver = 0;
                }
            }
            short *arr = row.data();
            //int n = row.length();
            //row.push_back(carryOver);
            //for (int z = 0; z < n; z++)
            //    number[z] = number[z]+arr[z];
//            reverse(row.begin(), row.end());
            //for (const short& a: row)
            //    std::cout << a;
            //std::cout << std::endl;
            //rows[0] = row;
            //row.clear();
            //zeroToAdd++;
        }
      //  for (int i =0; i < number.size

    }
    return "";
}
