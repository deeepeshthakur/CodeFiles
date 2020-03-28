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

long long dist(long long a, long long b, long long l, long long r){
	if(a>r || b<l)
		return 0ll;
	if(l<a){
		swap(l,a);
		swap(r,b);
	}

	return abs(max(l,a)-min(b,r));
}

void solve(){
	long long a,b,c,r;
	cin>>a>>b>>c>>r;
	if(a>b)
		swap(a,b);
	long long x=c-r,y=c+r;
	long long ans=abs(b-a)-dist(a,b,x,y);
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