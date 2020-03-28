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

int dp_fun(int h, int n, vector<vector<int>>& dp,vector<int>& a, vector<int>& b){
	if(h<=0)
		return 0;
	if(h>0&&n<0){
		return int(1e9);
	}
	if(dp[h][n]==-1){
		dp[h][n]=min(dp_fun(h,n-1,dp,a,b),dp_fun(h-a[n],n,dp,a,b)+b[n]);
		return dp[h][n];
	}
	return dp[h][n];
}

void solve(){
	int h,n;
	cin>>h>>n;
	vector<int> a(n,0),b(n,0);
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}

	vector<vector<int>> dp(h+1,vector<int>(n,-1));
	int ans=dp_fun(h,n-1,dp,a,b);
	cout<<ans<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}