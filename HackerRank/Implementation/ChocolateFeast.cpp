#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int ans( int n, int c, int m)
{
	int temp = 0, cho = 0;
	temp = n/c;
	cho = temp;
	while( temp >= m)
	{
		cho = cho + temp/m;
		int temp1 = 0;
		temp1 = temp/m + temp%m;
		temp = temp1;
	}
	return cho;
}

int main(){
    int t;
    std::cin >> t;
    for(int a0 = 0; a0 < t; a0++)
    {
        int n;
        int c;
        int m;
        std::cin >> n >> c >> m;
        std::cout << ans( n, c, m) << endl;
    }
    return 0;
}
