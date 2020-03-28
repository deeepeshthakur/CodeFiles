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

void f1(int ind, std::vector<std::vector<int>>& edges, std::vector<bool>& visited){
	if(visited[ind]){
		visited[ind] = false;
		for(int i = 0; i < edges[ind].size(); i++){
			f1(edges[ind][i],edges,visited);
		}
	}
}

void solve(int tc){
	int n,m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> edges(n);
	std::vector<bool> visited(n,true);
	for(int i = 0; i < m; i++){
		int c,d;
		std::cin >> c >> d;
		c--;
		d--;
		edges[c].push_back(d);
		edges[d].push_back(c);
	}

	int ans = 0;
	for(int i = 0; i < n; i++){
		if(visited[i]){
			ans++;
			f1(i,edges,visited);
		}
	}

	ans = n + ans - 2;

	std::cout << "Case #" << tc << ": " << ans << "\n";
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
	return 0;
}