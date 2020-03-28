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

void solve(){
	int n;
	cin>>n;
	vector<vector<long long>> grid(n,vector<long long>(3,0ll));
	vector<long long> dp(n+3,0ll);
	for(int i=0;i<n;i++)
		cin>>grid[i][0]>>grid[i][1]>>grid[i][2];

	for(int i=n-1;i>=0;i--)
		dp[i]=max(grid[i][0]+dp[i+1],max(grid[i][1]+dp[i+2],grid[i][2]+dp[i+3]));

	cout<<dp[0]<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int t;       
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}