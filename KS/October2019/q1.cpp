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

void solve(int i){
	int n,m,q,k;
	std::cin >> n >> m >> q;
	std::vector<bool> torn(n+1,true);
	torn[0] = false;
	for(int i = 0; i < m; i++){
		int ri;
		std::cin >> ri;
		torn[ri] = false;
	}

	std::vector<int> mul(n+1,0);
	for(int i = 1; i <= n; i++){
		k = 1;
		while(1ll*i*k <= 1ll*n){
			if(torn[i*k])
				mul[i]++;
			k++;
		}
	}

	long long ans = 0ll;
	for(int i = 0; i < q; i++){
		int ri;
		std::cin >> ri;
		ans += mul[ri];
	}

	std::cout << "Case #" << i << ": " << ans << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int t;
	std::cin >> t;
	for(int i = 1; i <= t; i++){
		solve(i);
	}

	// 	solve();
	return 0;
}
