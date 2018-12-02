#include <bits/stdc++.h>

using namespace std;
long long MOD = 998244353;

long long powfun(long long a, long long b){
	if(a == 0ll){
		return 0ll;
	}

	if(b == 0ll){
		return 1ll;
	}

	if(b == 1ll){
		return a;
	}

	long long x = powfun(a, b/2ll);
	x = (x*x)%MOD;
	if(b%2){
		x = (x*a)%MOD;
	}
	return x;
}

std::vector < long long > cArray{}, aArray{};
std::vector < std::vector < long long > > fdp{};
std::vector < long long > bArray{};
std::vector < long long > bSumArray{};

void filldpTable(int n){
	fdp[0][0] = 1;
	fdp[0][1] = aArray[0];
	for(int i = 0; i < n; i++){
		fdp[i][0] = 1;
	}

	for(int i = 1; i < fdp.size(); i++){
		for(int x = 1; x < fdp[i].size(); x++){
			fdp[i][x] = (fdp[i - 1][x] + (aArray[i]*fdp[i - 1][x - 1])%MOD)%MOD;
		}
	}

	for(int i = 0; i < fdp.size(); i++){
		for(int x = 0; x < fdp[i].size(); x++){
			if(x%2 == 1)
			fdp[i][x] *= -1ll;
		}
	}
}

long long getcf( int m){
	long long ans = 0;
	for(int i = 0; i <= m; i++){
		ans += (((cArray[m - i]*fdp[m][i]))%MOD + MOD)%MOD;
		ans %= MOD;
	}
	return ans;
}

long long getbf(int m, int n){
	if(m < n - 1){
		long long ai = aArray[m + 1], bi = bArray[m + 1];
		for(int i = 0; i < n ; i++){
			bSumArray[i] += (bi);
			bi *= ai;
			bi %= MOD;
			bSumArray[i] %= MOD;
		}
	}

	long long ans = 0ll;
	for(int j = 0; j <= m; j++){
		ans += ((bSumArray[m - j]*fdp[m][j])%MOD + MOD)%MOD;
		ans %= MOD;
	}

	return ans;
}

long long getaf(int m){
	long long ans = 0ll, p = 1ll, ai = aArray[m];
	for(int i = 0; i <= m; i++){
		ans += ((p*fdp[m][m - i])%MOD + MOD)%MOD;
		ans %= MOD;
		p *= ai;
		p %= MOD;
	}
	return ans;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n;
	std::cin >> n;
	cArray.resize(n, 0ll);
	aArray.resize(n, 0ll);
	bArray.resize(n, 0ll);
	bSumArray.resize(n + 1, 0ll);
	fdp.resize(n);
	for(int i = 0; i < n; i++){
		std::cin >> aArray[i];
	}

	for(int i = 0; i < n; i++){
		std::cin >> cArray[i];
	}

	for(int i = 0; i < n; i++){
		fdp[i].resize(i + 2, 0ll);
	}

	filldpTable(n);
	for(int i = n - 1; i >= 0; i--){
		long long a, b, c;
		c = getcf(i)%MOD;
		b = getbf(i, n)%MOD;
		a = getaf(i)%MOD;
		c -= b;
		c %= MOD;
		c += MOD;
		c %= MOD;
		a = powfun(a, MOD - 2)%MOD;
		bArray[i] = ((c*a)%MOD + MOD)%MOD;
	}

	for(int i = 0; i < n; i++){
		std::cout << bArray[i] << " ";
	}
	std::cout << "\n";
	return 0;
}