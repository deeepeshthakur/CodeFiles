#include <bits/stdc++.h>

using namespace std;
long long getsc(int a, int l){
	if(a > l){
		return 0ll;
	}

	long long ans = l;
	return ((ans*(ans + 1))/2ll - 1ll);
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n;
	std::cin >> n;
	// fillPrimeNumbers();
	if(n == 2){
		std::cout << 0 << "\n";
		return 0;
	}
	long long sc = 0;
	for(int i = 2; i <= n; i++){
		int l = n/i;
		sc += getsc(2, l);
	}

	std::cout << 4*sc << std::endl;	
	return 0;
}