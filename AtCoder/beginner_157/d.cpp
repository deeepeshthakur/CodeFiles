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

void dfs(int ind, int node, vector<bool>& vis, vector<int>& parent, vector<vector<int>>& gr){
	if(vis[ind]){
		vis[ind]=false;
		parent[ind]=node;
		for(int i=0;i<gr[ind].size();i++){
			dfs(gr[ind][i],node,vis,parent,gr);
		}
	}
}

void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	vector<vector<int>> gr(n),bl(n);
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		x--;
		y--;
		gr[x].pb(y);
		gr[y].pb(x);
	}

	for(int i=0;i<k;i++){
		int x,y;
		cin>>x>>y;
		x--;
		y--;
		bl[x].pb(y);
		bl[y].pb(x);
	}


	vector<bool> vis(n,true);
	vector<int> parent(n,-1),friends(n,0),enemies(n,0);
	for(int i=0;i<n;i++){
		dfs(i,i,vis,parent,gr);
	}

	for(int i=0;i<n;i++){
		friends[parent[i]]++;
	}

	for(int i=0;i<n;i++){
		friends[i]=friends[parent[i]];
	}

	for(int i=0;i<n;i++){
		int ans=friends[i]-1;
		set<int> s;
		for(int j=0;j<gr[i].size();j++)
			s.insert(gr[i][j]);
		for(int j=0;j<bl[i].size();j++)
			s.insert(bl[i][j]);
		for(auto itr=s.begin();itr!=s.end();itr++){
			if(parent[i]==parent[*itr])
				ans--;
		}
		cout<<max(0,ans)<<" ";
	}
	cout<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}