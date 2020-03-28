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
const int MOD=1e9+7;

void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> a(n,0);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	vector<int> dp(m);
	vector<vector<int>> min_dp(m,vector<int>(m,MOD));

	for(int i=0;i<dp.size();i++){
		dp[i]=max(a[i],a[n-m+i]);
	}


	for(int i=0;i<m;i++){
		int curr_min=MOD;
		for(int j=i;j<m;j++){
			curr_min=min(curr_min,dp[j]);
			min_dp[i][j]=curr_min;
		}
	}

	int ans=0;
	for(int i=0;i<=min(m-1,k);i++){
		for(int j=0;j<=i;j++){
			ans=max(ans,min_dp[j][m-1-i+j]);
		}
	}

	cout<<ans<<"\n";
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