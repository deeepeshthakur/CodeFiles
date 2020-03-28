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

long long dp_fun(int x, int y, int z, int n, int k, int p, vector<vector<long long>>& grid, vector<vector<vector<long long>>>& dp){
	if(z+y<=p){
		long long ans=0;
		for(int i=0;i<=k;i++)
			ans=max(ans,grid[x][z]+dp[x+1][z+y][i]);
		return ans;
	}
	return 0ll;
}

void solve(int test_case){
	int n,k,p;
	cin>>n>>k>>p;
	vector<vector<long long>> grid(n,vector<long long>(k+1,0ll));
	
	for(int i=0;i<n;i++)
		for(int j=1;j<=k;j++)
			cin>>grid[i][j];

	for(int i=0;i<n;i++)
		for(int j=1;j<=k;j++)
			grid[i][j]+=grid[i][j-1];


	vector<vector<vector<long long>>> dp(n,vector<vector<long long>>(p+1,vector<long long>(k+1,0ll)));
	for(int i=0;i<=k;i++){
		if(p-i>=0){
			dp[n-1][p-i][i]=grid[n-1][i];
		}
	}

	for(int i=n-2;i>=0;i--){
		for(int j=0;j<=p;j++)
			for(int z=0;z<=k;z++){
				dp[i][j][z]=dp_fun(i,j,z,n,k,p,grid,dp);
			}
	}

	long long ans=0;
	for(int i=0;i<=k;i++)
		ans=max(ans,dp[0][0][i]);

	cout<<"Case #"<<test_case<<": "<<ans<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int test_cases;
	cin >> test_cases;
	for(int i=1;i<=test_cases;i++){
		solve(i);
	}
	return 0;
}