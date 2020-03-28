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

void print_vec(vector<int>& a,int n=-1){
	n = (n==-1 ? a.size():n);
	for(int i=0;i<n;i++)
		cout << a[i] << (i<n-1 ? " ":"\n");
}

void print_vec(vector<long long>& a,int n=-1){
	n=(n==-1 ? a.size():n);
	for(int i=0;i<n;i++)
		cout << a[i] << (i<n-1 ? " ":"\n");
}

long long get_ans(int x, vector<long long>& a, vector<long long>& b, vector<long long>& c){
	for(int i=0;i<256;i++)
		for(int j=0;j<256;j++)
			b[(i&j)]+=(a[i]*a[j]);

	for(int i=0;i<256;i++)
		for(int j=0;j<256;j++)
			c[(i&j)]+=(a[i]*b[j]);
	return c[x]%MOD;
}

void solve(){
	int n;
	cin>>n;
	vector<int> a(n,0);
	for(int i=0;i<n;i++)
		cin>>a[i];

	vector<vector<pair<int,int>>> pre(256);
	for(int i=0;i<256;i++)
		for(int j=0;j<256;j++)
			pre[(i&j)].pb({i,j});

	vector<vector<int>> dp(n,vector<int>(256,0ll));
	vector<long long> ans(256,0ll),tmp(256,0ll),tmp2(256,0ll);
	for(int i=0;i<n;i++){
		dp[i][a[i]]++;
		if(i>0)
			for(int j=0;j<256;j++)
				dp[i][j]+=dp[i-1][j];
	}

	int m,l,r,x;
	cin>>m;
	for(int i=0;i<m;i++){
		int l,r,x;
		cin>>l>>r>>x;
		for(int j=0;j<256;j++){
			ans[j]=dp[r-1][j]-(l>1?dp[l-2][j]:0);
			tmp[j]=0;
			tmp2[j]=0;
		}
		cout<<get_ans(x,ans,tmp,tmp2,pre)<<"\n";
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}