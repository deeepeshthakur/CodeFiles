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

long min( long a, long b)
{
    if(a <= b)
        return a;
    else
        return b;
}

int main(){
    int t;
    std::cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long b;
        long w;
        std::cin >> b >> w;
        long x;
        long y;
        long z;
        std::cin >> x >> y >> z;

        long cost_x = 0, cost_y = 0;

        cost_x = min( x, y+z);
        cost_y = min( y, x+z);

        std::cout << ( b*cost_x + w*cost_y) << endl;
    }
    return 0;
}
