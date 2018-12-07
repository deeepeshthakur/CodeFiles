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

int modul = 1000000007;
unsigned long long auxilary_table[1000];
bool flag = true;

unsigned long long auxilary_func( int n)
{
	unsigned long long ans = 0;
	if(auxilary_table[n-1] == 0)
	{
		auxilary_table[n-1] = auxilary_func(n-1) + auxilary_func(n-2) + auxilary_func(n-3) + auxilary_func(n-4);
		if(auxilary_table[n-1] > modul)
		{
			auxilary_table[n-1] %= modul;
			//flag = false;
		}
		ans = auxilary_table[n-1];
	}
	else
	{
		ans = auxilary_table[n-1];
	}
	return ans;
}


using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    for(int index = 0; index < 1000; index++)
    	auxilary_table[index] = 0;
    auxilary_table[0] = 1;
    auxilary_table[1] = 2;
    auxilary_table[2] = 4;
    auxilary_table[3] = 8;

    int test_cases = 0;
    std::cin >> test_cases;
    for(int index = 0; index < test_cases; index++)
    {
    	int N, M;
    	std::cin >> N >> M;
    	unsigned long long ways = auxilary_func(M);
    	unsigned long long ans = 1;
    	for(int x = 0; x < N; x++)
    	{
    		ans *= ways;
    		if(ans > modul)
    		{
    			ans %= modul;
    			flag = false;
    		}
    	}
    	int sub = 0;
    	if(N < 5)
    		sub = N -1;
    	else
    		sub = N;

    	if(flag)
    		ans -= sub;
    	std::cout << ans << "\n";
    }



    return 0;
}
