#include <cmath>
#include <cstring>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int mem[100001];

unsigned long long dp[2][100001];
int dp_index[2][100001];

unsigned long long maxi( unsigned long long a, unsigned long long b, unsigned long long c)
{
	unsigned long long ans = a;
	if(ans < b)
		ans = b;
	if(ans < c)
		ans = c;
	return ans;
}

unsigned long long max_possible_score(int index, int arr_index)
{
	unsigned long long ans = 0;
	if(index < 0)
		ans = 0;
	else
	{
		if(dp[arr_index][index] == -1)
		{
			int counter_index = 0;
			if(arr_index == 1)
				counter_index = 0;
			else
				counter_index = 1;
			unsigned long long t1 = mem[index] + max_possible_score( index - 1 - dp_index[counter_index][index-1], arr_index);
			unsigned long long t2 = mem[index] + mem[index-1] + max_possible_score( index - 2 - dp_index[counter_index][index-2], arr_index);
			unsigned long long t3 = mem[index] + mem[index-1] + mem[index - 2] + max_possible_score( index - 3 - dp_index[counter_index][index - 3], arr_index);
			dp[arr_index][index] = maxi( t1, t2, t3);

			if(dp[arr_index][index] == t1)
				dp_index[arr_index][index] = 1;
			else
			{
				if(dp[arr_index][index] == t2)
					dp_index[arr_index][index] = 2;
				else
					dp_index[arr_index][index] = 3;
			}
			
			ans = dp[arr_index][index];
		}
		else
		{
			ans = dp[arr_index][index];
		}
	}
	return ans;
}


unsigned long long func( int n)
{
	unsigned long long ans = 0;
	memset( dp, -1, sizeof(dp));
	memset( dp_index, 0, sizeof(dp_index));
	dp[0][0] = mem[0];
	dp[0][1] = mem[0] + mem[1];
	dp[0][2] = mem[0] + mem[1] + mem[2];
	dp[1][0] = mem[0];
	dp[1][1] = mem[0] + mem[1];
	dp[1][2] = mem[0] + mem[1] + mem[2];
	dp_index[0][0] = 1;
	dp_index[0][1] = 2;
	dp_index[0][2] = 3;
	dp_index[1][0] = 1;
	dp_index[1][1] = 2;
	dp_index[1][2] = 3;
	for(int index = 3; index < n; index++)
	{
		unsigned long long temp;
		temp = max_possible_score( index, 0);
		temp = max_possible_score( index, 1);
	}
	ans = dp[0][n-1];
r	eturn ans;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    memset( mem, 0, sizeof(mem));
    int testcases = 0;
    std::cin >> testcases;
    for(; testcases > 0; testcases--)
    {
    	int n = 0;
    	std::cin >> n;
    	for(int index = 0; index < n; index++)
    		std::cin >> mem[n - 1 - index];
    	unsigned long long result = func(n);
    	std::cout << result << "\n";
    	memset( mem, 0, n*sizeof(int));
    }
    return 0;
}
