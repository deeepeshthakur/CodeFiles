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

void bfs(int ind, vector<bool>& vis, vector<vector<int>>& gr, vector<int>& dist, int d){
	if(vis[ind]){
		vis[ind]=false;
		dist[ind]=d;
		for(int i=0;i<gr[ind].size();i++)
			bfs(gr[ind][i],vis,gr,dist,dist[ind]+1);
	}
}

void solve(){
	int n,x,y;
	cin>>n>>x>>y;
	x--;
	y--;
	vector<vector<int>> gr(n);
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		gr[a-1].pb(b-1);
		gr[b-1].pb(a-1);
	}

	vector<int> dist_x(n,-1), dist_y(n,-1);
	dist_x[x]=0;
	dist_y[y]=0;
	vector<bool> vis_x(n,true), vis_y(n,true);
	bfs(x,vis_x,gr,dist_x,0);
	bfs(y,vis_y,gr,dist_y,0);

	int ans=0;
	for(int i=0;i<n;i++){
		if(dist_y[i]>dist_x[i] && (dist_y[i]-dist_x[i])%2==0){
			// cout<< i << " " << dist_x[i] << " " << dist_y[i] << "\n";
			ans=max(ans,dist_y[i]); 
		}

		if(dist_y[i]>dist_x[i] && (dist_y[i]-dist_x[i])%2!=0){
			// cout<< i << " " << dist_x[i] << " " << dist_y[i] << "\n";
			ans=max(ans,(dist_y[i]-dist_x[i])/2+dist_x[i]); 
		}

		if(dist_y[i]==dist_x[i] && dist_y[x]==2*dist_y[i])
			ans=max(ans,dist_y[i]);

	}
	cout<<ans<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}