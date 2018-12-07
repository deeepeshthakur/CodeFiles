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
    int m;
    std::cin >> n >> m;
    std::vector<int> c(m);
    for(int c_i = 0;c_i < m;c_i++){
       std::cin >> c[c_i];
    }

    std::sort( c.begin(), c.end());

    int max = 0;
    for( int index = 0; index < m-1; index++)
    {
    	if((c[index+1] - c[index]) > max)
    		max =  (c[index+1] - c[index]);
    }

    int dist = max/2;
    if((c[0] - 0) > dist)
    	dist = c[0] - 0;
    if((n-1) - c[m-1] > dist)
    	dist = n - 1 - c[m-1];

    std::cout << dist << endl;
    
    return 0;
}
