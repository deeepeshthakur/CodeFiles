#include <bits/stdc++.h>

using namespace std;

void solve( int n, unsigned long long k, int x){
	unsigned long long divi = 1000000007;
	std::vector< std::vector < unsigned long long > > dpArray( 3, std::vector < unsigned long long >( n, 0));
	dpArray[0][0] = 1;
	for(int index = 1; index < n; index++){
		dpArray[0][index] = (dpArray[1][index - 1] + dpArray[2][index - 1])%divi;
		dpArray[1][index] = (dpArray[0][index - 1] + dpArray[2][index - 1])%divi;
		dpArray[2][index] = ((k - 2)*dpArray[1][index])%divi;
	}

	int ans = 0;
	if(x == 1){
		ans = (int)dpArray[0][n - 1];
	}
	else{
		ans = (int)dpArray[1][n - 1];
	}
	std::cout << ans << std::endl;
}

int main(){
	int n = 0, x = 0;
	unsigned long long k;
	std::cin >> n >> k >> x;
	solve( n, k, x);
	return 0;
}
