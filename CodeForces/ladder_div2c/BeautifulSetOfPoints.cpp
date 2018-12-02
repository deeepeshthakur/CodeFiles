#include <bits/stdc++.h>

using namespace std;

int main(){
	int m, n;
	std::cin >> n >> m;
	if(n > m){
		n = m;
	}
	if(m > n){
		m = n;
	}

	std::cout << m + 1 << "\n";
	for(int index = 0; index <= m; index++){
		std::cout << index << " " << m - index << "\n";
	}
	return 0;
}