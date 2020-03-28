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
const long long mul = 1e6+1;

long long pow_mod(long long a, long long b){
	if(a==0)
		return 0ll;

	if(b==0)
		return 1ll;

	if(b==1)
		return a%MOD;

	long long x = pow_mod(a,b/2);
	if(b%2==1)
		return (((x*x)%MOD)*a)%MOD;

	return (x*x)%MOD;
}

void solve(){
	long long a,b,x, y;
	std::cin >> x >> y;
	a = 2*y-x;
	b = 2*x-y;
	std::cout << a%3 << " " << b%3 << "\n";
	if(a%3 != 0 || b%3 != 0){
		std::cout << 0 << "\n";
		return;
	}

	a/=3;
	b/=3;

	std::vector<long long> dp(int(a+b+1),1ll);
	for(int i=2;i<dp.size();i++){
		dp[i] = (dp[i-1]*(1ll*i))%MOD;
	}

	std::cout << (dp[a+b]*(pow_mod((dp[a]*dp[b])%MOD,MOD-2)))%MOD << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	// int t;
	// std::cin >> t;
	// while(t--){
	// 	solve();
	// }

	solve();
	return 0;
}