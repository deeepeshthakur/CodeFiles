#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n {};
    std::cin >> n;

    std::vector < int > arr;
    for( int index = 0; index < n; index++)
    {
    	int temp;
    	std::cin >> temp;
    	arr.push_back(temp);    	
    }

    std::sort( arr.begin(), arr.end());
    // for( auto x: arr)
    // 	cout << x << " ";
    // cout << endl;

    int temp = 0;
    int count = 0;
    int max = 0;
    for( int index = 0; index < n; index++)
    {
    	if(arr[index] == temp)
    		{
    			count++;
    			//cout << arr[index] << " MMMMM " << temp << endl;
    		}
    	else
    	{
    		temp = arr[index];
    		count = 1;
    	}

    	if( max < count)
    		{
    			max = count;
    			//cout << max << " n " << endl;
    		}
    }
    // cout << n << endl;
    // cout << max << endl;
    cout << n - max << endl;
    return 0;
}
