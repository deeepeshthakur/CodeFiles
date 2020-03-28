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

void edit_q(ind,st,l,r,index,val,)

void solve(){
	int n;
	cin>>n;
	vector<pair<int,long long>> p(n);
	for(int i=0;i<n;i++){
		cin>>p[i].first;
		p[i].first--;
	}

	for(int i=0;i<n;i++){
		cin>>p[i].second;
	}

	vector<long long> sc(n,0ll),dp(n,0ll);
	for(int i=0;i<n;i++){
		sc[p[i].first]=p[i].second;
	}	

	for(int i=0;i<n;i++){
		if(i>0)
			dp[i]+=dp[i-1];
		dp[i]+=sc[i];
	}

	vector<long long> st(4*n+100,0ll);



}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}