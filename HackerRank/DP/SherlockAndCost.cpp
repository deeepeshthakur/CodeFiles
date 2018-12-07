#include <bits/stdc++.h>

using namespace std;

int cost(std::vector <int> &arr) {
    // Complete this function
    int odd_sum = 0, even_sum = 0, num_odd = 0, num_even = 0;

    for( int index = 0; index < arr.size(); index++)
    {
    	if(index%2)
    	{
    		if(!(index == 0 || index == arr.size() - 1))
    		{
    			odd_sum += (2*arr[index]);
    			num_odd += 2;
    		}
    		else
    		{
    			odd_sum += (arr[index]);
    			num_odd++;
    		}

    	}
    	else
    	{
    		if(!(index == 0 || index == arr.size() - 1))
    		{
    			even_sum += (2*arr[index]);
    			num_even += 2;
    		}
    		else
    		{
    			even_sum += (arr[index]);
    			num_even++;
    		}
    	}
    }

    odd_sum = odd_sum - num_even;
    even_sum = even_sum - num_odd;

    int maxi = 0;

    if(odd_sum > even_sum)
    	maxi = odd_sum;
    else
    	maxi = even_sum;

    return maxi;
}

int main() { 
    int t;
    std::cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        std::cin >> n;
        std::vector<int> arr(n);
        for(int arr_i = 0; arr_i < n; arr_i++){
           std::cin >> arr[arr_i];
        }
        int result = cost(arr);
        std::cout << result << endl;
    }
    return 0;
}
