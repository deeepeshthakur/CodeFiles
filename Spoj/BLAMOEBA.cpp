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

long long sq_f(long long a){
	return (a*a)%MOD;
}

long long pow_mod(long long a, long long b){
	if(a == 0ll)
		return 0ll;

	if(b == 0ll)
		return 1ll;

	if(b == 1ll)
		return a%MOD;

	if(b%2 == 1){
		return (sq_f(pow_mod(a,b/2)%MOD)*(a%MOD))%MOD;
	}

	return sq_f(pow_mod(a,b/2)%MOD);
}

void solve(){
	long long m,n;
	std::cin >> m >> n;
	long long x,y;
	y = pow_mod(m%MOD,n%MOD);
	x = (((y + MOD - 1)%MOD)*(pow_mod((m + MOD - 1)%MOD,MOD - 2)%MOD))%MOD;
	std::cout << x << " " << y << "\n";
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
