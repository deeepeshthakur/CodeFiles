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
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n {};
    std::cin >> n;
    std::vector < int> p_of_x;
    for( int index = 0; index < n; index++)
    {
    	int temp {};
    	std::cin >> temp;
    	p_of_x.push_back( temp);
    }

    // for( int index = 0; index < n; index++)
    // 	cout << p_of_x[index] << " ";
    // cout << endl;

    std::vector < int > p_of_p (n);
    for( int index = 0; index < n; index++)
    	p_of_p[index] = p_of_x[p_of_x[index] - 1];

    // for( int index = 0; index < n; index++)
    // 	cout << p_of_p[index] << " ";
    // cout << endl;

    std::vector < int > double_inverse (n);
    for( int index = 0; index < n; index++)
    	double_inverse[p_of_p[index] - 1] = index;

    for( int index = 0; index < n; index++)
    	cout << double_inverse[index] + 1<< " ";
    
    cout << endl;
    return 0;
}
