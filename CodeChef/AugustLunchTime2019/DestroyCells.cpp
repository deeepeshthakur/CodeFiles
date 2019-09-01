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

int f1(int n, int m, int k){
	std::vector<std::vector<bool>> grid(n,std::vector<bool>(m,false));
	int ctr = 0;
	for(int i = 0;i < n; i++){
		for(int j = 0; j < m; j++){
			ctr++;
			if(k == 0 || ctr%(k+1) == 1){
				grid[i][j] = true;
			}
		}
	}

	ctr = 0;
	for(int j = 0; j < m; j++){
		for(int i = 0; i < n; i++){
			ctr++;
			if(k == 0 || ctr%(k+1) == 1){
				grid[i][j] = true;
			}
		}
	}

	ctr = 0;
	for(int i = 0; i< n; i++){
		for(int j = 0; j < m; j++){
			ctr += (grid[i][j] ? 1 : 0);
		}
	}
	return ctr;
}

void solve(){
	int n,m;
	std::cin >> n >> m;
	std::vector<int> dp(11,0);
	for(int i = 10;i >= 0; i--){
		dp[i] = f1(n,m,i);
	}

	for(int i = 0; i < 11; i++){
		std::cout << i << " " << dp[i] << std::endl;
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	solve();
	return 0;
}