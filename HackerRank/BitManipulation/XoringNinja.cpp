#include<bits/stdc++.h>
#define iint int
#define pll std::pair<iint,iint>
#define rep(i,a,b) for(iint i=(iint)a;i<(iint)b;i++)
#define per(i,a,b) for(iint i=(iint)a;i>(iint)b;i--)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define full(a) a.begin(),a.end()
#define rfull(a) a.rbegin(),a.rend()

using namespace std;
const double pi=acos(-1.0);
const double pii=2*pi;
const double eps=1e-6;
const long long MOD=1e9+7;

long long pow_mod(long long a, long long b){
	if(a == 0)
		return 0ll;

	if(b == 0)
		return 1ll;

	if(b == 1)
		return a%MOD;

	long long x = pow_mod(2ll,b/2);
	return (b%2 == 0 ? ((x*x)%MOD) : ((x*x*2)%MOD));
}

void solve(){
	long long n;
	std::cin >> n;
	long long a=0;
	for(int i=0;i<n;i++){
		long long b;
		std::cin >> b;
		a = (a|b);
	}

	long long mul = 1, pow_n,ans = 0;
	pow_n = pow_mod(2,n-1);
	while(a > 0){
		if(a%2 == 1)
			ans += (mul*pow_n)%MOD;
		a /= 2;
		mul = (mul*2)%MOD;
		ans %= MOD;
	}

	std::cout << ans << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int t;
	std::cin >> t;
	while(t--){
		solve();
	}

	// 	solve();
	return 0;
}