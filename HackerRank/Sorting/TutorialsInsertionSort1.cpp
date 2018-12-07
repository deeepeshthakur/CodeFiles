#include <bits/stdc++.h>

using namespace std;

void print_arr( int n, std::vector < int > &arr)
{
	for(int index = 0; index < n; index++)
		std::cout << arr[index] << " ";
	std::cout << endl;
}

void insertionSort1(int n, vector <int> arr) {
    // Complete this function
    int temp = arr[n - 1];
    bool flag = true;
    for( int index = n - 2; index >= 0 && flag; index--)
    {
    	if(arr[index] > temp)
    		{
    			arr[index + 1] = arr[index];
    			print_arr( n, arr);
    		}
    		else
    		{
    			arr[index + 1] = temp;
    			print_arr( n, arr);
    			flag = false; 
    		}
    }

    if(arr[0] > temp)
    {
    	arr[0] = temp;
    	print_arr( n, arr);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    insertionSort1(n, arr);
    return 0;
}
