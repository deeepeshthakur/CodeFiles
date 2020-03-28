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

void dfs(int ind, int k, std::vector<std::vector<int>>& gr, std::vector<bool>& vis, std::vector<std::pair<int,int>>& st_gr){
	if(vis[ind]){
		vis[ind]=false;
		st_gr[k].F = std::min(st_gr[k].F,ind);
		st_gr[k].S = std::max(st_gr[k].S,ind);
		for(int i=0;i<gr[ind].size();i++){
			dfs(gr[ind][i],k,gr,vis,st_gr);
		}
	}
}

void solve(){
	int n,m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> gr(n);
	for(int i=0;i<m;i++){
		int a,b;
		std::cin >> a >> b;
		a--;
		b--;
		gr[a].pb(b);
		gr[b].pb(a);
	}

	int j=0;
	std::vector<std::pair<int,int>> st_gr;
	std::vector<bool> vis(n,true);
	for(int i=0;i<n;i++){
		if(vis[i]){
			st_gr.push_back({i,i});
			dfs(i,j,gr,vis,st_gr);
			j++;
		}
	}
	// std::cout<<st_gr.size()<<"\n";
	std::sort(full(st_gr));
	if(st_gr.size()>1){
		int ctr =0;
		std::vector<std::pair<int,int>> l_r;
		std::vector<int> tot;
		l_r.pb({st_gr[0].F,st_gr[0].S});
		int ind = 0;
		for(int j = 1;j<st_gr.size();j++){
			if(l_r[ind].F > st_gr[j].S || st_gr[j].F > l_r[ind].S){
				ind++;
				l_r.pb({st_gr[j].F,st_gr[j].S});
				tot.pb(ctr);
				ctr=0;
			}
			else{
				l_r[ind].F = min(l_r[ind].F,st_gr[j].F);
				l_r[ind].S = max(l_r[ind].S,st_gr[j].S);
				ctr++;
			}
			if(j==st_gr.size()-1){
				tot.pb(ctr);
			}
		}
		int smmm=0;
		for(int j=0;j<tot.size();j++){
			smmm += tot[j];
		}
		std::cout << smmm << "\n";
	}
	else{
		std::cout << "0\n";
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