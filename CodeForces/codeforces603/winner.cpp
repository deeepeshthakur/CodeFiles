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
	int ans=0;
	vector<int> dp;
	ans=1;
	dp.pb(0);
	int tmp = n+1;
	while(dp[dp.size()-1]!=n){
		int curr = dp[dp.size()-1];
		tmp = n/(curr+1);
		ans++;
		dp.pb(n/tmp);
		tmp = n/dp[dp.size()-1];
	}
	cout<<dp.size()<<"\n";
	for(int i=0;i<dp.size();i++)
		cout << dp[i] << (i<dp.size()-1 ? " ":"\n");
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