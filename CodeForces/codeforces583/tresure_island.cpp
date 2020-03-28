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

bool is_valid(int x, int y, int n, int m){
	return (x > -1 && y > -1 && x < n && y < m);
}

bool f2(std::vector<std::vector<bool>>& grid){
	int n = grid.size(),m = grid[0].size();
	std::vector<std::vector<bool>> vis(n,std::vector<bool>(m,true));

	std::queue<std::pair<int,int>> bfsq;
	if(is_valid(0,1,n,m) && grid[0][1]){
		bfsq.push({0,1});
		vis[0][1] = false;
	}
	
	if(is_valid(1,0,n,m) && grid[1][0]){
		bfsq.push({1,0});
		vis[1][0] = false;
	}
	int x,y;
	while(bfsq.size() > 1){
		x = bfsq.front().first;
		y = bfsq.front().second;
		bfsq.pop();
		if(is_valid(x+1,y,n,m) && vis[x+1][y] && grid[x+1][y]){
			vis[x+1][y] = false;
			bfsq.push({x+1,y});
		}
		if(is_valid(x,y+1,n,m) && vis[x][y+1] && grid[x][y+1]){
			vis[x][y+1] = false;
			bfsq.push({x,y+1});
		}
	}

	x = bfsq.front().first;
	y = bfsq.front().second;

	return ((x == n-1) && (y == m-1));
}

bool f1(std::vector<std::vector<bool>>& grid){
	int n = grid.size(),m = grid[0].size();
	std::vector<std::vector<bool>> vis(n,std::vector<bool>(m,false));
	vis[0][0] = true;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(vis[i][j] && grid[i][j]){
				if(is_valid(i+1,j,n,m) && grid[i+1][j]){
					vis[i+1][j] = true;
					// std::cout << i+1 << " " << j << std::endl;
				}
				if(is_valid(i,j+1,n,m) && grid[i][j+1]){
					vis[i][j+1] = true;
					// std::cout << i << " " << j+1 << std::endl;
				}
			}
		}
	}

	return vis[n-1][m-1];
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,m;
	std::cin >> n >> m;
	std::vector<std::vector<bool>> grid(n,std::vector<bool>(m,false));
	for(int i = 0; i < n ; i++){
		std::string s;
		std::cin >> s;
		for(int j = 0; j < m; j++){
			grid[i][j] = (s[j] == '.');
		}
	}

	if(!f1(grid)){
		std::cout << "0\n";
		return 0;
	}

	if(!f2(grid)){
		std::cout << "1\n";
		return 0;
	}

	std::cout << "2\n";
	return 0;
}