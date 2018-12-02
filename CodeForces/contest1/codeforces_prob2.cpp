#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool check( int a, int b, int c)
{
	int ans = 0;
	bool result;
	ans = (a^(b^c));
	if(ans == 0)
		result = true;
	else
		result = false;
	// std::cout << a << " " << b << " " << c << " " << ans << " " << result <<"\n";
	return result;
}

int aux_func( int n)
{
	int result = 0;
	for( int a = 1; a <= n; a++)
	{
		for( int b = 1; b <= a; b++)
		{
			int c = a - b + 1;
			for(;c <= b; c++)
			{
				if(check( a, b, c))
					{
						result++;
						//std::cout << result << "\n";
					}
			}
		}
	}
	return result;
}

int main()
{
	int n;
	std::cin >> n;
	int result = aux_func(n);
	std::cout << result << "\n";
	return 0;
}