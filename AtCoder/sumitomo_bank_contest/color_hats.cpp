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
	vector<int> a(n,0);
	vector<long long> dp(n,0ll);
	for(int i=0;i<n;i++)
		cin>>a[i];
	if(a[0]==0){
		dp[0]=3;
	}
	for(int i=1;i<n;i++){
		if(a[i]==a[i-1]+1){
			dp[i] = (3ll*dp[i-1])%MOD;
		}
		else{
			dp[i] = (2ll*dp[i-1])%MOD;
		}
	}
	long long ans = (3ll*dp[n-1])%MOD;
	cout << ans << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	solve();
	
	return 0;
}