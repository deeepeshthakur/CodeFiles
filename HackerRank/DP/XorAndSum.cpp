#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int modul = 1000000007;
unsigned long long GP_sum = 0;

void auxilary_function()
{
	unsigned long long curr_term = 1;
	for(int index  = 1; index <= 5; index++)
	{
		curr_term *= 2;
		curr_term %= modul;
		std::cout << curr_term << " ";
		GP_sum += curr_term;
		GP_sum %= modul;
	}
	std::cout << "\n";
}

unsigned long long sum_calc( std::string binary_xor)
{
	unsigned long long ans = 0;
	unsigned long long multiplier = 1;

	for(int index = 0; index < binary_xor.length(); index++)
	{
		ans += (multiplier*(binary_xor[index] - '0'));
		ans %= modul;
		multiplier *= 2;
		multiplier %= modul;
	}

	std::cout << ans << " " << GP_sum << "\n";

	ans *= GP_sum;
	ans %= modul;
	return ans;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    auxilary_function();

    std::string temp_a{}, temp_b{};
    std::cin >> temp_a >> temp_b;

    int length = temp_a.length();
    if(temp_b.length() > length)
    	length = temp_b.length();

    int a_index_max = temp_a.length() - 1, b_index_max = temp_b.length() - 1;
    std::string a(length, '0'), b(length, '0'), ans(length, '0');
    for(int index = 0; index < length; index++)
    {
    	if(index <= a_index_max)
    	{
    		a[index] = temp_a[a_index_max - index];
    	}

    	if(index <= b_index_max)
    	{
    		b[index] = temp_b[b_index_max - index];
    	}
    }

    for(int index = 0; index < length; index++)
    {
    	if(a[index] == b[index])
    		ans[index] = '0';
    	else
    		ans[index] = '1';
    }

    std::cout << ans << "\n";
    unsigned long long result = sum_calc( ans);
    std::cout << result << "\n";
    return 0;
}
