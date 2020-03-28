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

inline bool is_valid(int i, int j, int h, int w){
	return (-1<i && i<h && -1<j && j<w); 
}

int get_max(int x, int y, vector<vector<bool>>& grid){
	int h=grid.size(),w=grid[0].size();
	vector<vector<int>> sc(h,vector<int>(w,int(1e6)));
	vector<vector<bool>> vis(h,vector<bool>(w,true));
	queue<pair<int,int>> bfs_q;
	sc[x][y]=0;
	vis[x][y]=false;
	bfs_q.push({x,y});
	int i,j,ti,tj;
	while(!bfs_q.empty()){
		ti=bfs_q.front().first;
		tj=bfs_q.front().second;
		bfs_q.pop();
		i=ti+1;j=tj;
		if(is_valid(i,j,h,w)&&grid[i][j]&&vis[i][j]){
			sc[i][j]=sc[ti][tj]+1;
			vis[i][j]=false;
			bfs_q.push({i,j});
		}

		i=ti-1;j=tj;
		if(is_valid(i,j,h,w)&&grid[i][j]&&vis[i][j]){
			sc[i][j]=sc[ti][tj]+1;
			vis[i][j]=false;
			bfs_q.push({i,j});
		}

		i=ti;j=tj+1;
		if(is_valid(i,j,h,w)&&grid[i][j]&&vis[i][j]){
			sc[i][j]=sc[ti][tj]+1;
			vis[i][j]=false;
			bfs_q.push({i,j});
		}

		i=ti;j=tj-1;
		if(is_valid(i,j,h,w)&&grid[i][j]&&vis[i][j]){
			sc[i][j]=sc[ti][tj]+1;
			vis[i][j]=false;
			bfs_q.push({i,j});
		}
	}
	int ans=0;
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			if(grid[i][j]){
				ans=max(ans,sc[i][j]);
			}
		}
	}
	return ans;
}

void solve(){
	int h,w;
	cin>>h>>w;
	vector<vector<bool>> grid(h,vector<bool>(w,false));
	for(int i=0;i<h;i++){
		string s;
		cin>>s;
		for(int j=0;j<w;j++)
			if(s[j]=='.')
				grid[i][j]=true;
	}

	int ans=0;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(grid[i][j])
				ans=max(ans,get_max(i,j,grid));
		}
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