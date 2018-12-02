#include <bits/stdc++.h>

using namespace std;

bool test1( int n, int m, int x, int y){
	bool ans = false;
	if(n == 1 && m == 1){
		return true;
	}
	
	if((n - 1)%x == 0 && (m - 1)%y == 0){
		ans = true;
	}
	return ans;
}

bool test2( int n, int m, int x, int y){
	bool ans = false;
	if(n == 1 || m == 1){
		return false;
	}

	if((n - 2)%x == 0 && (m - 2)%y == 0){
		ans = true;
	}
	return ans;
}

int main(){
	int testCases = 0;
	std::cin >> testCases;
	int x, y, n, m;
	while(testCases--){
		std::cin >> n >> m >> x >> y;
		if(test1( n, m, x, y) || test2( n, m, x, y)){
			std::cout << "Chefirnemo\n";
		}
		else{
			std::cout << "Pofik\n";
		}
	}
	return 0;
}