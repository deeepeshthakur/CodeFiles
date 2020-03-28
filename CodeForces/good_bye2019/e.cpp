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

long long sq(long long a){
	return a*a;
}

long long dist(pair<long long,long long>& a,pair<long long,long long>& b){
	return sq(a.first-b.first)+sq(a.second-b.second);
}

void solve(){
	int n;
	cin>>n;
	vector<pair<long long,long long>> pts(n,{0ll,0ll});
	for(int i=0;i<n;i++){
		cin>>pts[i].first>> pts[i].second;
	}
	vector<vector<long long>> dp(n,vector<long long>(n,0ll));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			dp[i][j]=dist(pts[i],pts[j]);
		}
	}
	long long gd=dp[0][1];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			gd=__gcd(gd,dp[i][j]);

	int t=0;
	vector<int> gp(n,0);
	for(int i=0;i<n;i++){
		gp[i]=(dp[0][i]/gd)%2;
		t+=gp[i];
	}

	cout<<t<<"\n";
	for(int i=0;i<n;i++){
		if(gp[i]==1)
			cout<<i+1<<" ";
	}	
	cout<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}