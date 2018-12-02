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

int main()
{
	int n;
	int first = 0, last = 0;
	std::vector< std::vector< int > > tab( n, std::vector < int > (4));
	for(int index = 0; index < n; index++)
	{
		std::string temp{};
		std::cin >> temp;
		bool flag = true;
		int s_count = 0, h_count = 0, rs_count = 0, rh_count = 0, curr_noise = 0;
		std::vector < std::vector < int > > internal( temp.length(), std::vector < int > (2));
		for( int inner = 0; inner < temp.length() && flag; inner++)
		{
			if(temp[inner] == 's')
				s_count++;
			else
				h_count++;

			if(temp[temp.length() - 1 - inner] == 's')
				s_count++;
			else
				h_count++;

			internal[temp.length() - 1 - inner][0] = rs_count;
			internal[temp.length() - 1 - inner][1] = rh_count;
			if
		}
		tab[index][0] = h_count - s_count;
		tab[index][1] = s_count;
		tab[index][2] = h_count;
		
	}
	return 0;
}