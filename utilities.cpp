#include <iostream>
#include <string> 

using namespace std;

void printBinary(long int x)
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

int main()
{
	printBinary(64);
	return 0;
}

