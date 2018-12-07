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

long M = 1000000007;
int limit_num = 218;
std::vector < int > aux_table{}, aux_5 = { 2, 3 ,5 ,7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43}, aux_4 = { 2, 3, 5, 7 , 11, 13, 17, 19, 23, 29, 31}, aux_3 = { 2, 3, 5, 7, 11, 13, 17, 19, 23} ;
std::vector < std::vector < unsigned long long > > dp_table(limit_num);
std::vector < std::vector <int> > pre(limit_num);

int sum_digit( int n)
{
	int sum = 0;
	while(n > 0)
	{
		sum += n%10;
		n /= 10;
	}

	return sum;
}

bool check_sum( int sum, int digit)
{
	bool ans = false, flag = true;
	if( digit == 5)
	{
		for( int x = 0; x < aux_5.size() && flag; x++)
			if(sum == aux_5[x])
			{
				ans = true;
				flag = false;
			}
	}
	else
		if( digit == 4)
		{
			for( int x = 0; x < aux_4.size() && flag; x++)
				if(sum == aux_4[x])
				{
					ans = true;
					flag = false;
				}
		}
		else
			if( digit == 3)
			{
				for( int x = 0; x < aux_3.size() && flag; x++)
					if(sum == aux_3[x])
					{
						ans = true;
						flag = false;
					}
			}
	return ans;
}

bool check_num( int n, int digit, int curr_digit)
{
	bool ans = false;
	if(digit == 3)
	{
		//std::cout << "3*";
		int div = 1000;
		std::vector < int > temp_sum(curr_digit - digit + 1);
		for(int index = 0; index < temp_sum.size(); index++)
		{
			temp_sum[index] = sum_digit(n%div);
			n /= 10;
		}

		ans = true;
		for(int index = 0; index < temp_sum.size() && ans; index++)
		{
			ans = check_sum(temp_sum[index], digit);
		}
	}
	else
		if( digit == 4)
		{
			//std::cout << "4*";
			int div = 10000;
			std::vector < int > temp_sum(curr_digit - digit + 1);
			for(int index = 0; index < temp_sum.size(); index++)
			{
				temp_sum[index] = sum_digit(n%div);
				n /= 10;
			}

			ans = true;
			for(int index = 0; index < temp_sum.size() && ans; index++)
			{
				ans = check_sum(temp_sum[index], digit);
			}
		}
		else
			if(digit == 5)
			{
				//std::cout << "5*";
				int div = 100000;
				std::vector < int > temp_sum(curr_digit - digit + 1);
				for(int index = 0; index < temp_sum.size(); index++)
					{
						temp_sum[index] = sum_digit(n%div);
						n /= 10;
					}
					ans = true;
					for(int index = 0; index < temp_sum.size() && ans; index++)
						{
							ans = check_sum(temp_sum[index], digit);
						}
			}

	return ans;
}

void aux_func_call()
{
	int count = 0;
	// for( int index = 100; index < 1000; index++)
	// {
	// 	if(check_num( index, 3, 3))
	// 		{
	// 			aux_table.push_back(index);
	// 			count++;
	// 		}

	// }

	// for( int index = 1000; index < 10000; index++)
	// {
	// 	if(check_num( index, 4, 4))
	// 		if(check_num( index, 3, 4))
	// 			{
	// 				aux_table.push_back(index);
	// 				count++;
	// 			}
	// }


	for( int index = 10000; index < 100000; index++)
	{
		//std::cout << index << std::endl;
		if(check_num( index, 5, 5))
			if(check_num( index, 4, 5))
				if(check_num( index, 3, 5))
					{
						aux_table.push_back(index);
						count++;
					}
	}
	std::cout << count << "\n\n\n\n\n\n\n\n\n";
	limit_num = aux_table.size();
	dp_table.resize(limit_num);
	pre.resize(limit_num);
}

void aux_func_fill_pre()
{
	for(int x = 0; x < limit_num; x++)
	{
		int curr = aux_table[x];
		curr = curr/10;
		for( int y = 0; y < limit_num; y++)
		{
			if(aux_table[y]%10000 == curr)
				{
					pre[x].push_back(y);// std::cout << aux_table[y] << " ";
				}
		}
	}
	// for(int index = 0; index < limit_num; index++)
	// 	std::cout << pre[index].size() << " ";
	// std::cout << "\n";
}

unsigned long long func( int n)
{
	for(int x = 0; x < limit_num; x++)
		dp_table[x][0] = 1;

	for( int index = 1; index <= (n - 5); index++)
	{
		for( int x = 0; x < limit_num; x++)
		{
			unsigned long long temp = 0;
			for( int y : pre[x])
			{
				temp += dp_table[y][index-1];
			}
			temp %= M;
			dp_table[x][index] = temp;
		}
	}

	unsigned long long ans = 0;
	for(int index = 0; index < limit_num; index++)
	{
		ans += dp_table[index][n-5];
	}

	ans = ans%M;
	return ans;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int test_cases = 0;
    std::cin >> test_cases;
    aux_func_call();
    aux_func_fill_pre();
    // std::cout << aux_table.size() << "\n";

    for(int index = 0; index < test_cases; index++)
    {
    	int n;
    	std::cin >> n;
    	std::vector < unsigned long long > temp( n, -1);
    	for(int index = 0; index < limit_num; index++)
    		dp_table[index] = temp;

    	unsigned long long result = func(n);
    	std::cout << result << std::endl;
    }

    return 0;
}
