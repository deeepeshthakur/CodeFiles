#include <bits/stdc++.h>

using namespace std;
long long MOD = 1000000007;

long long powerF( long long a, long long b){
	if(a == 0){
		return 0ll;
	}

	if(b == 0){
		return 1ll;
	}

	if(b == 1){
		return a%MOD;
	}

	long long x = powerF( a, b/2)%MOD;
	long long ans = (x*x)%MOD;


	if(b%2 == 1){
		ans *= a;
		ans %= MOD;
	}
	return ans;
}

void solve(){
	int n, m;
	std::cin >> n >> m;
	long long nn = n, mm = (m*(m + 1))/2;
	long long ans = powerF(mm, nn) - powerF(mm-1, nn);
	cout << ans << endl;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int t; std::cin >> t;
	while(t--){
		solve();
	}
	return 0;
}

