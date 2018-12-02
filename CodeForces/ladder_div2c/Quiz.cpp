#include <bits/stdc++.h>

using namespace std;
long long MOD = 1000000009;

long long powF( long long a, long long b){
	if(a == 0){
		return 0ll;
	}

	if(b == 0){
		return 0ll;
	}

	if(b == 1){
		return a;
	}

	long long x = powF( a, b/2);
	x = (x*x)%MOD;
	if(b%2){
		x = (x*a)%MOD;
	}

	return x;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	long long n, m, k;
	std::cin >> n >> m >> k;
	if((n - m + 1)*(k - 1) >= m){
		std::cout << m%MOD << "\n";
		return 0;
	}
	long long hA = std::max((m - (n - m)*(k - 1)), 0ll);
	long long score = (n - m)*(k - 1);
	long long q = hA/k, r = hA%k;
	long long sc = 2*k*std::max(powF( 2ll, q) - 1, 0ll);
	sc += r;
	std::cout << (sc + score)%MOD << "\n";
	return 0;
}