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
const long long MOD=998244353ll;

void solve(){
	int n,s;
	cin>>n>>s;
	vector<int> a(n,0);
	for(int i=0;i<n;i++)
		cin>>a[i];
	long long ans=0;
	for(int i=0;i<n;i++){
		vector<long long> dp(s+1,0ll);
		
	}
}	

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}