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

int rec_f(int n, int w, std::vector<int>& a, std::vector<int>& b){
	std::vector<std::vector<std::pair<int,int>>> dp(n+1,std::vector<std::pair<int,int>>(w+1,{0,0}));

	for(int i=0;i<=n;i++){
		for(int j=0;j<=w;j++){
			if(i==0 || j ==0)
				dp[i][j].F = 0;
				dp[i][j].S = 0;
			else{
				if(dp[i-1][j].S <= j){
					if()
					dp[i][j] = std::max(b[i-1]+dp[i-1][j-a[i-1]], dp[i-1][j]);
				}
				else{
					dp[i][j] = dp[i-1][j];
				}
			}
		}
	}
	return dp[n][w];
}

void solve(){
	int n, w;
	std::cin >> n >> w;
	std::vector<int> a(n,0), b(n,0);
	for(int i=0;i<n;i++)
		std::cin >> a[i] >> b[i];

	std::cout << rec_f(n,w-1,a,b) << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	// int t;
	// std::cin >> t;
	// while(t--){
	// 	solve();
	// }

	solve();
	return 0;
}