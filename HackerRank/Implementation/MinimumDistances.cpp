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

int abs( int a, int b)
{
	if(a <= b)
		return b - a;
	else
		return a - b;
}

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i = 0;i < n;i++){
       cin >> A[i];
    }

    int min = n;
    for( int index = 0; index < n; index++)
    {
    	int l = index - 1;
    	int r = index + 1;
    	int count = 1;
    	bool r_check, l_check;

    	if( l < 0)
    		l_check = false;
    	else
    		l_check = true;

    	if( r >= n)
    		r_check = false;
    	else
    		r_check = true;

    	while(r_check || l_check)
    	{
    		int temp = A[index];
    		if( temp == A[l])
    		{
    			if( abs( index, l) < min)
    				min = abs( index, l);
    			l_check = false;
    		}

    		if( temp == A[r])
    		{
    			if( abs( index, r) < min)
    				min = abs( index, r);
    			r_check = false;
    		}
    		l = index - count;
    		r = index + count;
    		count++;
    		if( l < 0)
    			l_check = false;
    		else
    			l_check = true;
	    	
	    	if( r >= n)
	    		r_check = false;
	    	else
	    		r_check = true;

    	}
    }

    if( min < n )
    	std::cout << min << endl;
    else
    	std::cout << -1 << endl;
    return 0;
}
