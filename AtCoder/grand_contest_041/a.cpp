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
	long long n,a,b;
	cin>>n>>a>>b;
	if((b-a)%2==0){
		cout<<(b-a)/2<<"\n";
	}
	else{
		long long ans=min(b-1,n-a);
		long long curra=a,currb=b;
		ans=min(ans,a+((b-a-1)/2));
		ans=min(ans,n-b+((b-a+1)/2));
		cout<<ans<<"\n";
	}
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