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

unsigned long long M = 1000000007;

unsigned long long same_tab[1201][1201], plusone_tab[1201][1201];

void aux_func_same_tab( int x, int y)
{
	if(same_tab[x][y] != 0)
	{
		unsigned long long temp;
		if(same_tab[x][y] == 1)
			temp = 1;
		else
			temp = (same_tab[x][y])*(same_tab[x][y] - 1);
		temp %= M;
		same_tab[x+1][y] += temp;
		same_tab[x+1][y] %= M;

		plusone_tab[x+1][y+1] += plusone_tab[x][y+1] + 1;
		plusone_tab[x+1][y+1] %= M;

	}
}

void aux_func_plusone_tab( int x, int y)
{
	if(plusone_tab[x][y] != 0)
	{
		unsigned long long temp = (plusone_tab[x][y])*(plusone_tab[x][y] - 1);
		temp %= M;
		same_tab[x+1][y] += temp;
		same_tab[x+1][y] %= M;

		plusone_tab[x+1][y+1] += plusone_tab[x][y+1] + 1;
		plusone_tab[x+1][y+1] %= M;
	}
}

unsigned long long func( std::vector < int > &arr)
{
	int prev = arr[0];
	for(int x = 0; x < arr.size() - 1; x++)
	{
		if(prev <= arr[x])
		{
			for(int y = 0; y <= x; y++)
			{
				aux_func_same_tab( x, y);
			}
		}

		for(int y = 0; y <= x; y++)
		{
			aux_func_plusone_tab( x, y);
		}

		prev = arr[x];
	}

	unsigned long long ans = 0;
	for( int y = 0; y < 1201; y++)
	{
		// if(arr[arr.size() - 1] >= arr[arr.size() - 2])
		// {
		// 	ans += same_tab[arr.size() - 1][y];
		// 	ans %= M;
		// }

		ans += plusone_tab[arr.size() - 1][y];
		ans %= M;
	}

	for(int x = 0; x < arr.size(); x++)
	{
		for( int y = 0; y < arr.size(); y++)
		{
			std::cout << same_tab[x][y] + plusone_tab[x][y] << "        ";
		}
		std::cout << "\n";
	}

	return ans;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    for( int x = 0; x < 1201; x++)
    	for( int y = 0; y < 1201; y++)
    		{
    			same_tab[x][y] = 0;
    			plusone_tab[x][y] = 0;

    			// if(x == 0)
    			// 	same_tab[0][y] = 1;
    		}
    		same_tab[0][0] = 1;

    int n;
    std::cin >> n;
    std::vector < int > arr(n);

    for( int index = 0; index < n; index++)
    {
    	std::cin >> arr[index];
    }

    unsigned long long result = func( arr);
    std::cout << result << "\n";

    return 0;
}
