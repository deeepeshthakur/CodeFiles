#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	std::cout << 10 << " " << 8 << " " << 40 << endl;
	for( int x = 0; x < 10; x++)
	{
		for(int y = 0; y < 8; y++)
			std::cout << x*8 + y + 10<< " ";
		std::cout << endl;
	}
	return 0;
}