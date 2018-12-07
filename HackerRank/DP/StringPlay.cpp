#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int start_a = 0, end_b = 3000, end_a, start_b;
int dp_table[3000][3000];

int max_num( int a, int b)
{
	if(a < b)
		return b;
	return a;
}

int max_palindrome_length( std::string &str, int start, int end)
{
	int ans = 0;
	if(dp_table[start][end] == -1)
	{
		if(start >= end)
		{
			if(start > end)
			{
				dp_table[start][end] = 0;
				ans = dp_table[start][end];
			}
			else
			{
				dp_table[start][end] = 1;
				ans = dp_table[start][end];
			}
		}
		else
		{
			if(str[start] == str[end])
			{
				dp_table[start][end] = 2 + max_palindrome_length( str, start + 1, end - 1);
				ans = dp_table[start][end];
			}
			else
			{
				dp_table[start][end] = max_num( max_palindrome_length( str, start + 1, end), max_palindrome_length( str, start, end - 1));
				ans = dp_table[start][end];
			}
		}
	}
	else
	{
		ans = dp_table[start][end];
	}

	return ans;
}

int game_play( std::string str)
{
	end_b = str.length() - 1;
	if(end_b == 1)
		return 1;

	int ans = 1;
	for(int index = 1; index < end_b; index++)
	{
		end_a = index;
		start_b = end_a + 1;
		int temp = max_palindrome_length( str, start_a, end_a)*max_palindrome_length( str, start_b, end_b);
		if(temp > ans)
			ans = temp;
	}

	return ans;
}



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    std::memset( dp_table, -1, sizeof(dp_table));
    std::string input_str{};
    std::cin >> input_str;
    int result = game_play( input_str);
    std::cout << result << "\n";
    return 0;
}
