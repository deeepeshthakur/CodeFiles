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

long long get_and(long long l, long long r){
	while(l<r){
		r-=(r&-r);
	}
	return r;
}

void solve(){
	long long l,r,k;
	cin>>l>>r>>k;
	long long tmp=1ll,b=0ll;
	while(tmp<l){
		tmp*=2ll;
		b=tmp-1;
	}
	long long ans=0;
	bool flag=true;
	while(flag){
		if(b-k+1>=l && b<=r){
			ans=max(ans,get_and(b-k+1,b));
		}
		if(tmp>r){
			flag=false;
		}

		if(tmp<=r){
			tmp*=2ll;
			b=min(r,tmp-1);
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