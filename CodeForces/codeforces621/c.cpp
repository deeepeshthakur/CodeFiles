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
	string s;
	cin>>s;
	int n=s.size();
	vector<long	long> a(26,0);
	vector<vector<int>> dp(n,vector<int>(26,0));

	for(int i=n-1;i>=0;i--){
		a[int(s[i]-'a')]++;
		dp[i][int(s[i]-'a')]=1;
		if(i<n-1){
			for(int j=0;j<26;j++)
				dp[i][j]+=dp[i+1][j];
		}
	}

	vector<vector<long long>> ans(26,vector<long long>(26,0ll));
	for(int i=0;i<n-1;i++){
		for(int j=0;j<26;j++){
			ans[int(s[i]-'a')][j]+=dp[i+1][j];
		}
	}

	long long fin_ans=0;
	for(int i=0;i<26;i++)
		fin_ans=max(fin_ans,a[i]);

	for(int i=0;i<26;i++){
		for(int j=0;j<26;j++)
			fin_ans=max(fin_ans,ans[i][j]);
	}

	cout<<fin_ans<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int t=1;       
	// cin >> t;
	while(t--){
		solve();
	}
	return 0;
}