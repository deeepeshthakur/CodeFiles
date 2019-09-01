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
const double MOD=1e9+7;

void solve(){
	int n, mx = 0;
	std::cin >> n;
	std::vector<int> g(n,0), f(n,0);
	for(int i = 0; i < n; i++){
		std::cin >> g[i];
	}

	for(int i = 0; i < n; i++){
		std::cin >> f[i];
	}

	for(int i = 0; i < n; i++){
		mx = std::max(mx,std::max(0,g[i]*20 - f[i]*10));
	}

	std::cout << mx << std::endl;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int t = 0;
	std::cin >> t;
	while(t--){
		solve();
	}
	return 0;
}