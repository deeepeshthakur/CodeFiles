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
	std::vector<std::pair<int,int>> edges(2*m,{0,0});
	for(int i=0;i<m;i++)
	{	
		int a,b;
		std::cin >> a >> b;
		a--;
		b--;
		edges.pb({a,b});
		edges.pb({b,a});
	}

	std::sort(full(edges));

	std::vector<std::vector<int>> gr(n);
	for(int i=0;i<edges.size();i++){
		gr[edges[i].S].pb(edges[i].F);
	}

	if(m < n-1){
		std::cout << "0\n";
		return;
	}

	std::vector<int> nodes(n,0);
	for(int i=0;i<n;i++){
		nodes[i] = i;
	}
	int ctr = 0;
	while(nodes.size()>0){
		std::vector<int>
	}
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