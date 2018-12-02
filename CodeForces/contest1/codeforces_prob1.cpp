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

bool auxilary_func( int n, int m)
{
	int x, y;
	bool ans;
	x = m - 1;
	y = n - x;
	if(x >= 0 && y%2 == 0 && y >= 0)
		ans = true;
	else
		ans = false;
	return ans;
}

int main()
{
	int n, m;
	std::cin >> n >> m;
	bool result = auxilary_func( n, m);
	if(result)
	{
		std::cout << "Yes\n";
	}
	else
	{
		std::cout << "No\n";
	}

	return 0;
}