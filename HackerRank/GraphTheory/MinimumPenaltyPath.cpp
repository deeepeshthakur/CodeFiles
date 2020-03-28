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

void dfs(int a, std::vector<std::vector<std::pair<int,int>>>& gr, std::vector<bool>& vis, std::vector<int>& cst){
	if(vis[a]){
		vis[a] = false;
		for(int i = 0; i < gr[a].size(); i++){
			if(cst[gr[a][i].second] == 1){
				dfs(gr[a][i].first,gr,vis,cst);
			}
		}
	}
}


int f1(int a, int b, std::vector<std::vector<std::pair<int,int>>>& gr, std::vector<bool>& vis, std::vector<int>& cst){
	dfs(a,gr,vis,cst);
	return (vis[b] ? 0 : 1);
}

void solve(){
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<std::pair<int,int>>> gr(n);
	std::vector<bool> vis(n,true);
	std::vector<int> cst(m,0), cr_cost(m,0);
	for(int i = 0; i < m; i++){
		int a, b;
		std::cin >> a >> b >> cst[i];
		a--; b--;
		gr[a].push_back({b,i});
		gr[b].push_back({a,i});
	}

	int x,y;
	std::cin >> x >> y;
	x--; y--;

	int ans = 0, flag = 1;
	while(flag <= 1024){
		for(int i = 0; i < n; i++){
			vis[i] = true;
		}

		for(int i = 0; i < m; i++){
			cr_cost[i] = cst[i]%2;
			cst[i] /= 2;
		}

		ans += flag*f1(x,y,gr,vis,cr_cost);
		flag *= 2;
	}

	if(ans == 0){
		std::cout << -1 << std::endl;
	}
	else{
		std::cout << ans << std::endl;
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}