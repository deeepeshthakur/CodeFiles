#include <cmath>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;
int modul = 1000000007;

unsigned long long calc_value( std::vector < int > arr)
{
	unsigned long long ans = 0;
	std::vector < unsigned long long > auxilary_sum( arr.size(), 0), result( arr.size(), 0), powers_of_2( arr.size(), 1);
	auxilary_sum[0] = arr[0];
	result[0] = arr[0];
	powers_of_2[0] = 1;
	for(int index = 1; index < arr.size(); index++)
	{
		powers_of_2[index] = (powers_of_2[index - 1]*2)%modul;
		auxilary_sum[index] = (auxilary_sum[index - 1] + arr[index]*powers_of_2[index])%modul;
		result[index] = (2*result[index - 1] + arr[index]*(powers_of_2[index]*2 - 1) + auxilary_sum[index - 1])%modul;
	}
	ans = result[arr.size() - 1];
	return ans;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int length = 0;
    std::cin >> length;
    std::vector < int > input_array(length);
	for(int x = 0; x < length; x++)
		std::cin >> input_array[x];
	int result = calc_value( input_array);
	std::cout << result << "\n";    
    return 0;
}
