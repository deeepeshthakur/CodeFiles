#include <bits/stdc++.h>

using namespace std;

void print_arr( std::vector < int > &arr)
{
	int n = arr.size();
	for(int index = 0; index < n; index++)
		std::cout << arr[index] << " ";
	std::cout << endl;
}

void insertionSort1(int n, vector <int> &arr) {
    // Complete this function
    int temp = arr[n - 1];
    bool flag = true;
    for( int index = n - 2; index >= 0 && flag; index--)
    {
    	if(arr[index] > temp)
    		{
    			arr[index + 1] = arr[index];
    			//print_arr(arr);
    		}
    		else
    		{
    			arr[index + 1] = temp;
    			//print_arr(arr);
    			flag = false; 
    		}
    }

    if(arr[0] > temp)
    {
    	arr[0] = temp;
    	//print_arr(arr);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    for(int index = 2; index <= n; index++)
    {
    	insertionSort1( index, arr);
    	print_arr( arr);
    }
    return 0;
}
