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

struct node{
	int wt,p,lca;
	long long a,b;
	std::vector<int> c,rc;
};

void make_tree(std::vector<node>& nodes){
	int n=nodes.size();
	std::vector<bool> vis(n,true);
	std::vector<std::vector<int>> edges(n);
	rep(i,0,n-1)
	{
		int u,v;
		std::cin>>u>>v;
		u--;v--;
		edges[u].pb(v);
		edges[v].pb(u);
	}
	std::queue<int> q{};
	q.push(0);
	vis[0]=false;
	nodes[0].p=-1;
	while(!q.empty()){
		int cr = q.front();
		q.pop();
		rep(i,0,edges[cr].size()){
			if(vis[edges[cr][i]]){
				vis[edges[cr][i]]=false;
				q.push(edges[cr][i]);
				nodes[cr].c.pb(edges[cr][i]);
				nodes[edges[cr][i]].p=cr;
			}
		}
	}
}

void dfs1(int cr,std::vector<node>& nodes,int x){
	rep(i,0,nodes[cr].c.size()){
		dfs1(nodes[cr].c[i],nodes,x);
		nodes[nodes[cr].c[i]].wt!=x&&(((nodes[cr].wt=(nodes[cr].wt^nodes[nodes[cr].c[i]].wt))&&(nodes[nodes[cr].c[i]].wt=-1))||true);
	}
}

void getXorWt(std::vector<node>& nodes,int x){
	int n = nodes.size();
	dfs1(0,nodes,x);
}

void dfs2(int cr,std::vector<node>& nodes,int p){
	if(nodes[cr].wt!=-1&&cr!=0){
		nodes[p].rc.pb(cr);
		p=cr;
	}
	rep(i,0,nodes[cr].c.size()){
		dfs2(nodes[cr].c[i],nodes,p);
	}
}

void getRTree(std::vector<node>& nodes){
	int n=nodes.size();
	dfs2(0,nodes,0);
}

void dfs3(int cr,std::vector<node>& nodes,int x){
	nodes[cr].a=0;
	nodes[cr].b=0;
	if(nodes[cr].wt==x){
		nodes[cr].a=1;
	}
	if(nodes[cr].wt==0){
		nodes[cr].b=1;
	}

	rep(i,0,nodes[cr].rc.size()){
		dfs3(nodes[cr].rc[i],nodes,x);
	}

	rep(i,0,nodes[cr].rc.size()){
		int j=nodes[cr].rc[i];
		long long t1,t2;
		t1 = (nodes[cr].a*nodes[j].b+nodes[cr].b*nodes[j].a+nodes[cr].a*nodes[j].a)%MOD;
		t2 = (nodes[cr].a*nodes[j].a+nodes[cr].b*nodes[j].b+nodes[cr].b*nodes[j].a)%MOD;
		nodes[cr].a=t1;
		nodes[cr].b=t2;
	}
}

long long solve(std::vector<node>& nodes,int x){
	dfs3(0,nodes,x);
	return nodes[0].a%MOD;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,x;
	std::cin>>n>>x;
	std::vector<node> nodes(n);
	rep(i,0,n){
		std::cin>>nodes[i].wt;
	}
	make_tree(nodes);
	getXorWt(nodes,x);
	getRTree(nodes);
	long long ans = solve(nodes,x);
	std::cout<<ans<<"\n";
	return 0;
}