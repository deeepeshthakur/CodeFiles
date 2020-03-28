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
	long long a,b,c,d,e,f;
	cin>>a>>b>>c>>d>>e>>f;
	long long ans=0;
	for(int i=0;i<=a;i++){
		long long x,y;
		x=min(i*1ll,min(a,d));
		y=min(min(b,c),max(0ll,d-x));
		x = e*x+f*y;
		if(x>ans)
			ans=x;
	}

	for(int i=0;i<=b;i++){
		long long x,y;
		y=min(min(i*1ll,b),min(c,d));
		x=min(a,max(0ll,d-y));
		x = e*x+f*y;
		if(x>ans)
			ans=x;
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