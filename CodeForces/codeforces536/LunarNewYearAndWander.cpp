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

struct node{
	std::vector<int> paths;
	node(){
		paths.resize(0);
	}
	void pf(){
		std::sort(full(paths));
	}
};

void dfs(int i,std::vector<bool>& vis,std::priority_queue<int, std::vector<int>, std::greater<int>>& pq,std::vector<node>& gp){
	if(vis[i]){
		vis[i]=false;
		rep(j,0,gp[i].paths.size()){
			pq.push(gp[i].paths[j]);
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,m;
	std::cin>>n>>m;
	std::vector<node> gp(n);
	rep(i,0,m){
		int a,b;
		std::cin>>a>>b;
		a--;
		b--;
		gp[a].paths.pb(b);
		gp[b].paths.pb(a);
	}
	rep(i,0,n){
		gp[i].pf();
	}
	std::vector<bool> vis(n,true);
	std::vector<int> ans{};
	std:: priority_queue <int, std::vector<int>, std::greater<int> > pq;
	pq.push(0);
	while(!pq.empty()){
		int ft=pq.top();
		pq.pop();
		if(vis[ft]){
			ans.pb(ft+1);
			dfs(ft,vis,pq,gp);
		}
	} 
	rep(i,0,n){
		std::cout<<ans[i]<<" ";
	}
	std::cout<<"\n";
	return 0;
}