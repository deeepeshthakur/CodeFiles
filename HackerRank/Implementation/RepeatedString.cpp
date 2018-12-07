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

long quotient( long n, long l)
{
	long quo = (n/l);
	return quo;
}

long remainder( long n, long l)
{
	long quo = (n/l);
	std::cout << quo << endl;
	long rem = n - quo*l;
	return rem;
}


int main(){
    string s;
    cin >> s;
    long n;
    cin >> n;
    long len = s.length();
    long quo = quotient( n, len);
    long rem = remainder( n, len);
    long count =0, count_a_rem = 0;
    for( int index = 0; index < len; index++)
    {
    	if( s[index] == 'a')
    		count++;
    	if( index + 1 == rem)
    		count_a_rem = count;
    }

    long ans = quo*count + count_a_rem;
    cout << len << " " << rem << " " << count << " " << count_a_rem << " ";
    cout << ans << endl;
    return 0;
}
