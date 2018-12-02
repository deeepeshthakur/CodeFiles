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

bool aux_func( unsigned long long n, unsigned long long k)
{
	bool ans;
	if(n%2 == 1)
	{
		ans = true;
		for(int index = 3; index < k && ans; index++)
		{
			if(n%index != index - 1)
				ans = false; 
		}
		
	}
	else
	{
		if(k >= 2)
		{
			ans = false;
		}
		else
		{
			ans = true;
		}
	}
	return ans;
}

int main()
{
	unsigned long long n, k;
	std::cin >> n >> k;
	bool ans = aux_func( n, k);
	if(ans)
		std::cout << "Yes\n";
	else
		std::cout << "No\n";
	return 0;
}