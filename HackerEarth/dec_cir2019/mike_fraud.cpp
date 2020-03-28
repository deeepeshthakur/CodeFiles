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

bool is_factor(int l,int r,vector<int>& fc, vector<vector<int>>& dp){
	for(int i=0;i<fc.size();i++)
		if(fc[i]>(dp[r][i]-(l>0?dp[l-1][i]:0)))
			return false;
	return true;
}

void solve(){
	int n;
	long long k;
	cin>>n>>k;
	vector<long long> a(n,0ll);
	for(int i=0;i<n;i++)
		cin>>a[i];
	vector<int> factor_k,factor_count;
	long long tmpk=k;
	for(int i=2;i*i<=tmpk;i++){
		if(tmpk%i==0){
			int x=i,y=0;
			while(tmpk%x==0){
				y++;
				tmpk/=x;
			}
			factor_k.pb(x);
			factor_count.pb(y);
		}
	}
	if(tmpk>1){
		factor_k.pb(tmpk);
		factor_count.pb(1);
	}

	vector<vector<int>> dp(n,vector<int>(factor_k.size(),0));
	for(int i=0;i<n;i++){
		long long ai=a[i];
		for(int j=0;j<dp[i].size();j++){
			while(ai%factor_k[j]==0){
				ai/=factor_k[j];
				dp[i][j]++;
			}
			dp[i][j]+=(i>0?dp[i-1][j]:0);
		}
	}
	long long ans=0;
	for(int i=0;i<n;i++){
		if(is_factor(i,n-1,factor_count,dp)){
			int l=i,r=n-1,mid;
			while(r-l>1){
				mid=(l+r)/2;
				if(is_factor(i,mid,factor_count,dp))
					r=mid;
				else
					l=mid;
			}
			if(is_factor(i,l,factor_count,dp))
				ans+=(n-l);
			else
				ans+=(n-r);
		}
	}
	cout<<ans<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}