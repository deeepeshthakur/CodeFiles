#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
	int count = 1;
	std::string str{};
	std::cin >> str;

	for(auto x: str)
	{
		if((x >= 'A') && (x <= 'Z'))
			count++;
	}

	std::cout << count << std::endl;
	return 0;
}