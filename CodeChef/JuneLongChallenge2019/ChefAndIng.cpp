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
const long long int MOD=1e9+7;

void solve(){
	unsigned long long int n,k;
	std::cin >> n >> k;
	unsigned long long int t = ((k-1)/(n-1))%MOD;
	unsigned long long int ans = (k-1)%MOD + ((k%MOD)*t)%MOD + 5*MOD- ((((n-1)%MOD*500000004)%MOD)*(((t*t)%MOD + t)%MOD))%MOD - t%MOD;
	ans %= MOD;
	std::cout<< ans <<std::endl;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int t;
	std::cin >>t;
	while(t--){
		solve();
	}
	return 0;
}