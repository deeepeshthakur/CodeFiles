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

inline int grid_xy(int x,int y,vector<vector<long long>>& grid){
	return ((x>=0 && y>=0 && x<grid.size() && y<grid[0].size()) ? grid[x][y] : 0);
}

long long cal_prod(int x, int y, vector<vector<long long>>& grid,vector<pair<int,int>>& dir){
	int curr_x,curr_y;
	long long prod=0;
	for(int i=0;i<dir.size();i++){
		long long tmp=1;
		for(int j=0;j<4;j++){
			tmp *= grid_xy(x+j*dir[i].first,y+j*dir[i].second,grid);
		}
		prod = max(prod,tmp);
	}
	return prod;
}	

void solve(){
	int n=20;
	vector<pair<int,int>> dir{{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
	vector<vector<long long>> grid(20,vector<long long>(20,0ll)), dp(20,vector<long long>(20,0ll));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>grid[i][j];

	long long max_prod=0ll;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			max_prod = max(max_prod,cal_prod(i,j,grid,dir));

	cout << max_prod << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	solve();
	
	return 0;
}