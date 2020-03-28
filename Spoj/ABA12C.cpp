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

int f3(int a, int b){
	if(a != -1 && b != -1)
		return a+b;
	return -1;
}

int f2(int a, int b){
	if(a != -1 && b != -1)
		return std::min(a,b);

	if(a == -1)
		return b;

	return a;
}

void solve(){
	int n, k;
	std::cin >> n >> k;
	std::vector<int> prices(k,-1);
	std::vector<std::vector<int>> dp(n+1,std::vector<int>(k+1,-1));

	for(int i = 0; i < k; i++){
		std::cin >> prices[i];
	}

	for(int i = 1; i <= k; i++){
		dp[1][i] = prices[i-1];
	}

	for(int i = 2; i <= n; i++){
		for(int j = 1; j <= k; j++){
			for(int m = 1; m <= j; m++){
				dp[i][j] = f2(dp[i][j],f3(dp[1][m],dp[i-1][j-m]));
			}
		}
	}

	// for(int i = 0; i < dp.size(); i++){
	// 	for(int j = 0; j < dp[0].size(); j++){
	// 		std::cout << dp[i][j] << " ";
	// 	}
	// 	std::cout << std::endl;
	// }

	int ans = -1;
	for(int i = 1; i <= n; i++){
		ans = f2(ans,dp[i][k]);
	}

	std::cout << ans << std::endl;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int t;
	std::cin >> t;
	while(t--){
		solve();
	}
	return 0;
}