#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool binary_search( std::vector < int> arr, int s, int e, int key)
{
	int m = (s+e)/2;
	if((s > e) || ((s == e) && (arr[s] != key)) || (s < 0) || (e >= arr.size()))
		{ 
			//std::cout << "step 1    ";
			return false;
		}
	if((arr[s] == key) || (arr[s+1] == key) || (arr[e] == key) || (arr[e-1] == key) || (arr[m] == key))
		{
			//std::cout << " step 2     ";
			return true;
		}
	if(arr[m] > key)
		e = m - 1;
	if(arr[m] < key)
		s = m + 1;
	//std::cout << " s = " << s << " e = " << e << endl;
	return binary_search( arr, s, e, key);
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, d;
    std::cin >> n >> d;
    std::vector < int> seq (n);
    //cout << seq.max_size() << endl; 
    for( int index = 0; index < n; index++)
    {
    	std::cin >> seq[index];
    }
    	
    std::cout << " Done ..... " << endl;

    int count = 0;
    for( int index = 0; index < n - 2; index++)
    {
    	int temp = seq[index];
    	if(binary_search( seq, index, n - 1, temp + d) && binary_search( seq, index, n - 1, temp + 2*d))
    		count++;
    	std::cout << count << endl;
    }

    std::cout << count << endl;

    // int che;
    // std::cin >> che;

    // if(binary_search( seq, 0, n-1, che))
    // 	std::cout << " True " << endl;
    // else
    // 	std::cout << " False " << endl;

    return 0;
}
