#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
    }

    std::sort( arr.begin(), arr.end());
    bool flag = true;
    //int while_count = 0;
    cout << n << endl;
    while(flag)
    {
    	flag = false;
    	bool min_check = true;
    	int min = 0;
    	int temp = 0;
    	for( int index = 0; index < n; index++)
    	{
    		if( arr[index] != 0)
    		{
    			//flag = true;
    			if(min_check)
    				{
    					min = arr[index];
    					min_check = false;
    					//cout << " Min = " << min << endl;
    				}

    			arr[index] -= min;
    			if(arr[index] != 0)
    				temp++;
    		}
    	}

    	if(temp > 0)
    	{
    		cout << temp << endl;
    		flag = true;
    	}
    	// while_count++;
    	// if(while_count > 20)
    	// 	flag = false;

    }

    return 0;
}
