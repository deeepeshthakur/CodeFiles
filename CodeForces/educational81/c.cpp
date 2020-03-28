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

bool get_query(int l, int r, string& s, string& t, int n, int m, vector<vector<int>>& dp){
	if(r-l+1>n)
		return false;
	int pos=0;
	for(int i=l;i<=r;i++){
		if(pos>=n || dp[pos][int(t[i]-'a')]>=n)
			return false;
		else
			pos=dp[pos][int(t[i]-'a')]+1;
	}
	return true;
}

void solve(){
	string s,t;
	cin>>s>>t;
	int n=s.size(),m=t.size();
	vector<vector<int>> dp(n,vector<int>(26,n+1));

	for(int i=n-1;i>=0;i--){
		if(i<n-1){
			for(int j=0;j<26;j++){
				dp[i][j]=dp[i+1][j];
			}
		}

		dp[i][int(s[i]-'a')]=i;
	}

	for(int i=0;i<m;i++){
		if(dp[0][int(t[i]-'a')]>=n){
			cout<<-1<<"\n";
			return;
		}
	}

	int ans=0;
	int ind=0;
	while(ind<m){
		int l=ind,r=m-1,mid;
		while(r-l>1){
			// cout<<l<<" "<<r<<endl;;
			mid=(l+r)/2;
			if(get_query(ind,mid,s,t,n,m,dp)){
				l=mid;
			}
			else{
				r=mid;
			}
		}

		if(get_query(ind,r,s,t,n,m,dp)){
			ind=r+1;
			ans++;
		}
		else{
			ind=l+1;
			ans++;
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