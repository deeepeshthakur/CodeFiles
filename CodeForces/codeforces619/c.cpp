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
	long long n,m;
	cin>>n>>m;
	if(n==m){
		cout<<n*(n+1ll)/2ll<<"\n";
		return;
	}

	long long del=n-m,eq=del/(m+1),rem=del%(m+1);
	long long tmp=(m+1ll-rem)*eq*eq + rem*(eq+1ll)*(eq+1ll);
	long long ans=(n*(n+1ll)/2)-((tmp+n-m)/2ll);
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