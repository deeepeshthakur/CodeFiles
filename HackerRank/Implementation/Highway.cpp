#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int ans( std::vector < int > arr, int i, int j)
{
    int temp = 4;
    for( int index = i; index <= j; index++)
    {
        if( temp > arr[index])
            temp = arr[index];

        if( temp == 1)
            index = j + 1;
    }

    return temp;
}

int main(){
    int n;
    int t;
    std::cin >> n >> t;
    std::vector<int> width(n);
    for(int width_i = 0;width_i < n;width_i++){
       std::cin >> width[width_i];
    }
    for(int a0 = 0; a0 < t; a0++){
        int i;
        int j;
        std::cin >> i >> j;
        std::cout << ans( width, i, j) << endl;
    }
    return 0;
}
