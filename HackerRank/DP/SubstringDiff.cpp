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

std::string P{}, Q{};
int p_length, q_length;
int mismatches = 0;
int dp_table[1501][1501];
int dp_table2[1501][1501];

int auxilary_function( int x, int y)
{
	if( x > p_length || y > q_length)
	{
		dp_table[x][y] = 0;
		dp_table2[x][y] = 0;
		return 0;
	}

	if(dp_table[x][y] == -1)
	{
		int curr_length = auxilary_function( x + 1, y + 1);
		if(P[x + curr_length] == Q[y + curr_length])
		{
			if(P[x] == Q[y])
			{
				dp_table2[x][y] = dp_table2[x + 1][y + 1];
				dp_table[x][y] = dp_table[x + 1][y + 1] + 1;
			}
			else
			{
				dp_table2[x][y] = dp_table2[x + 1][y + 1] + 1;
				if(dp_table2[x][y] <= mismatches)
					dp_table[x][y] = dp_table[x + 1][y + 1] + 1;
				else
				{
					dp_table2[x][y] = mismatches;
					bool flag = true;
					for(int index = dp_table[x + 1][y + 1]; index >= 0 && flag; index--)
					{
						if(P[x + index] != Q[y + index])
						{
							dp_table[x][y] = index	;
							flag = false;
						}
					}

				}

			}
		} 
		else
		{
			if(P[x] == Q[y])
			{
				dp_table2[x][y] = dp_table2[x + 1][y + 1];
				dp_table[x][y] = dp_table[x + 1][y + 1] + 1;
			}
			else
			{
				dp_table2[x][y] = dp_table2[x + 1][y + 1] + 1;
				if(dp_table2[x][y] > mismatches)
				{
					dp_table2[x][y] = mismatches;
					dp_table[x][y] = dp_table[x + 1][y + 1];
				}
				else
				{
					dp_table[x][y] = dp_table[x + 1][y + 1] + 1;
				}
			}
		}
	}
	return dp_table[x][y];
}

int calc_string_diff( int n)
{
	int max_length = 0;
	p_length = P.length() - 1;
	q_length = Q.length() - 1;
	mismatches = n;
	std::memset( dp_table, -1, sizeof(dp_table));
	std::memset( dp_table2, 0, sizeof(dp_table2));
	int ans = 0;
	for(int x = P.length() - 1; x >= 0; x--)
	{
		for(int y = Q.length() - 1; y >= 0; y--)
		{
			int temp = auxilary_function( x, y);
			if(temp > max_length)
				max_length = temp;
		}
	}
	ans = max_length;
	return ans;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int test_cases = 0;
    std::cin >> test_cases;
    while(test_cases--)
    {
    	int n;
    	std::cin >> n;
    	std::cin >> P >> Q;
    	int ans = calc_string_diff(n);
    	std::cout << ans << "\n";
    }
    return 0;
}
