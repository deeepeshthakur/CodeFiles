#include<bits/stdc++.h>
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

int query(int n, vector<vector<int>>& dp, vector<int>& parent, vector<int>& level, int p, int q){
	if(level[p]<level[q])
		swap(p,q);
	int l=1;
	while(1<<l <= level[p])
		l++;

	for(int i=l;i>=0;i--)
		if(level[p]-(1<<i)>=level[q])
			p=dp[p][i];

	if(p==q)
		return p;
	for(int i=l;i>=0;i--){
		if(dp[p][i]!= -1 && dp[p][i]!=dp[q][i]){
			p=dp[p][i];
			q=dp[q][i];
		}
	}
	return parent[p];
}

void dfs(int ind, int father,int level, vector<bool>& vis, vector<int>& parent, vector<vector<int>>& gr, vector<vector<int>>& path_0_i,vector<int>& powers, vector<int>& level_array){
	if(vis[ind]){
		vis[ind]=false;
		parent[ind]=father;
		level_array[ind]=level;
		path_0_i[ind][powers[ind]]++;
		if(father!=-1){
			for(int i=0;i<26;i++){
				path_0_i[ind][i]+=path_0_i[father][i];
			}
		}
		for(int i=0;i<gr[ind].size();i++)
			dfs(gr[ind][i],ind,level+1,vis,parent,gr,path_0_i,powers,level_array);
	}
}

void solve(){
	int n;
	cin>>n;
	vector<int> powers(n,0),level(n,-1);
	vector<vector<int>> path_0_i(n,vector<int>(26,0));
	for(int i=0;i<n;i++){
		char c;
		cin>>c;
		powers[i]=int(c-'a');
	}

	vector<vector<int>> gr(n);
	for(int i=0;i<n-1;i++){
		int x,y;
		cin>>x>>y;
		x--;y--;
		gr[x].pb(y);
		gr[y].pb(x);
	}

	vector<int> fathers(n,-1);
	vector<bool> vis(n,true);
	dfs(0,-1,0,vis,fathers,gr,path_0_i,powers,level);

	int m=0;
	while(1<<m <= n){
		m++;
	}
	m+=10;

	vector<vector<int>> dp(n,vector<int>(m,-1));
	for(int i=0;i<n;i++){
		dp[i][0]=fathers[i];
	}

	for(int j=1;j<m;j++)
		for(int i=0;i<n;i++)
			if(dp[i][j-1]!=-1)
				dp[i][j]=dp[dp[i][j-1]][j-1];

	int q;
	cin>>q;
	// vector<int> ans(26,0);
	for(int i=0;i<q;i++){
		int p,q,lca,ans=0,ind_ans=0,tmp;
		cin>>p>>q;
		p--;
		q--;
		lca=query(n,dp,fathers,level,p,q);
		for(int j=0;j<26;j++){
			tmp=path_0_i[p][j]+path_0_i[q][j]-2*path_0_i[lca][j]+(powers[lca]==j?1:0);
			if(tmp>ans){
				ans=tmp;
				ind_ans=j;
			}
		}
		cout<<char(int('a')+ind_ans)<<"\n";
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}