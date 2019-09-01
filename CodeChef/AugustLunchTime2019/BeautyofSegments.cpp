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

long long f2(int x, int y, std::vector<int>& l, std::vector<int>& r, std::vector<std::vector<long long>>& dp){
	if(x == 0){
		return 0ll;
	}

	if(y <= l[x] || r[x] <= y){
		return dp[x][0];
	}

	return dp[x][1];
}

long long f1(long long a, long long b, int x, int y, std::vector<int>& l, std::vector<int>& r, std::vector<std::vector<long long>>& dp){
	if(x == 0){
		return 0ll;
	}

	if(y == 0){
		return dp[x - 1][0];
	}

	return std::min(a + dp[x - 1][1], b + f2(x - 1, l[x], l, r, dp) + f2(x - 1, r[x], l, r, dp));
}

void solve(){
	int n,q;
	long long a, b;
	std::cin >> n >> q >> a >> b;
	std::vector<int> l(n + 1,0),r(n + 1,0);
	for(int i = 1 ; i <= n; i++){
		std::cin >> l[i] >> r[i];
	}
	std::vector<std::vector<long long>> dp(n + 1,std::vector<long long>(2,0ll));
	for(int i = 1; i <= n; i++){
		dp[i][0] = f1(a,b,i,0, l, r, dp);
		dp[i][1] = f1(a,b,i,1, l, r, dp);
	}

	int x, y;
	for(int i = 0; i < q; i++){
		std::cin >> x >> y;
		std::cout << f2(x,y,l,r,dp) << "\n";
	}
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