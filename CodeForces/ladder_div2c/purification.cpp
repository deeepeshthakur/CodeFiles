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

void solve(){
	int n;
	std::cin >> n;
	std:vector<std::vector<bool>> grid(n, std::vector<bool>(n,true));
	std::vector<std::pair<int,int>> pnts;
	for(int i = 0; i < n; i++){
		std::string s;
		std::cin >> s;
		for(int j = 0; j < n; j++){
			grid[i][j] = (s[j] == '.'); 
		}
	}

	for(int i = 0; i < n; i++){
		bool flag = true;
		for(int j = 0; j < n && flag; j++){
			if(grid[i][j]){
				flag = false;
				pnts.push_back({i,j});
			}
		}
	}

	if(pnts.size() == n){
		for(int i = 0 ; i < n; i++){
			std::cout << pnts[i].F + 1 << " " << pnts[i].S + 1 << "\n";
		}
		return;
	}

	pnts.resize(0);
	for(int j = 0; j < n ; j++){
		bool flag = true;
		for(int i = 0; i < n && flag; i++){
			if(grid[i][j]){
				flag = false;
				pnts.push_back({i,j});
			}
		}
	}

	if(pnts.size() == n){
		for(int i = 0 ; i < n; i++){
			std::cout << pnts[i].F + 1 << " " << pnts[i].S + 1 << "\n";
		}
		return;
	}

	std::cout << -1 << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}