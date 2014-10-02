#include <iostream>
#include <string> 
#include "utilities.h"

using namespace std;

void printBinary(unsigned long x)
{
	int i = 0;
	string str;
	while(x)
	{
		i = x & 1;
		str = str + to_string(i);		
		x = x >> 1;
	}
	for (std::string::reverse_iterator rit=str.rbegin(); 
		rit!=str.rend(); ++rit)
    		std::cout << *rit;
	cout << endl;
}


