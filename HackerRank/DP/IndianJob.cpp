#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool auxilary_function( int n, int g, std::vector < int > dp_table)
{
	int curr_index1 = 0, curr_index2 = 0;
	for(int index = n - 1; index >= 0; index--)
	{
		if(curr_index1 <= curr_index2)
		{
			curr_index1 += dp_table[index];
		}
		else
			curr_index2 += dp_table[index];
		// std::cout << dp_table[index] << " " << curr_index1 << " " << curr_index2 << "\n";
	}
	// std::cout << curr_index1 << " " << curr_index2 << "\n";
	if(curr_index1 <= g && curr_index2 <= g)
		return true;
	else
		if(curr_index1 == g + 1 && curr_index2 < g || curr_index2 == g + 1 && curr_index1 < g)
			return true;
	return false;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int test_cases;
    std::cin >> test_cases;
    while(test_cases--)
    {
    	int N, G;
    	std::cin >> N >> G;
    	std::vector < int > dp_table( N, 0);
    	for(int index = 0; index < N; index++)
    		std::cin >> dp_table[index];
    	std::sort( dp_table.begin(), dp_table.end());

    	// for( int x : dp_table)
    	// 	std::cout << x << " ";
    	// std::cout << "\n";

    	bool ans = auxilary_function( N, G, dp_table);
    	if(ans)
    		std::cout << "YES\n";
    	else
    		std::cout << "NO\n";
    } 
    return 0;
}
