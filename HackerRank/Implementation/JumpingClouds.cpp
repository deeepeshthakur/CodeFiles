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


int main(){
    int n;
    std::cin >> n;
    std::vector<int> c(n);
    for(int c_i = 0;c_i < n;c_i++){
       std::cin >> c[c_i];
    }

    int curr = 0;
    int steps = 0;
    while( curr < n - 1)
    {
    	if((curr + 2 < n) && (c[curr + 2] == 0))
    	{
    		curr += 2;
    		steps++;
    	}
    	else
    		if(((c[curr+2]) == 1) || (curr + 2 >= n))
    			{
    				curr += 1;
    				steps++;
    			}
    }

    std::cout << steps << endl;

    return 0;
}