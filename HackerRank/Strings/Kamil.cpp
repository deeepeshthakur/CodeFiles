#include <iostream>
using namespace std;

int main()
{
	for( int count = 0; count < 10; count++)
	{
		char ch;
		int pro = 1, size = 0;
		std::cin >> ch;
		while((ch - 'A' >= 0) && (ch - 'A' <26) && (size < 20))
		{
			if((ch == 'L') || (ch == 'F') || (ch == 'T') || (ch == 'D'))
				pro *= 2;
			size++;
			std::cin >> ch;			
		}

		std::cout << pro << endl;
	}

	return 0;
}