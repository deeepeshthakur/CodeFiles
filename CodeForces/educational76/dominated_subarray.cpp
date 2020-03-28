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
	std::vector<std::vector<int>> dp(n);
	for(int i=0;i<n;i++){
		int a;
		std::cin >> a;
		dp[a-1].push_back(i);
	}

	int ans = n+1;
	for(int i=0;i<n;i++){
		for(int j=1;j<dp[i].size();j++){
			ans = std::min(ans,dp[i][j]-dp[i][j-1]+1);
		}
	}
	if(ans != n+1)
		std::cout << ans << "\n";
	else
		std::cout << "-1\n";
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

	// 	solve();
	return 0;
}