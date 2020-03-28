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

void solve(){
	int n,m;
	std::cin >> n >> m;
	// std::vector<std::pair<int,int>> vec(m,{0,0});
	std::vector<std::vector<int>> jury(n), cats(n);
	int a,b;

	for(int i = 0; i < m; i++){
		// std::cin >> vec[i].F >> vec[i].S;
		// vec[i].F--;
		// vec[i].S--;
		std::cin >> a >> b;
		a--;
		b--;
		jury[a].pb(b);
		cats[b].pb(a);
	}

	int minm = n;
	for(int i = 0; i < n; i++){
		minm = (minm > jury[i].size()) ? jury[i].size() : minm;
	}

	std::vector<int> min_jury;
	for(int i = 0; i < n; i++){
		if(jury[i].size() == minm){
			min_jury.pb(i);
		}
	}

	
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