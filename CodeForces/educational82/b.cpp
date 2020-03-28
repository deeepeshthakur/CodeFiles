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
const long long MOD=1e9;

bool tf(long long skip, long long g, long long b, long long n){
	long long m=skip/b;
	long long tmp=g*m+g,tmp2;
	if(tmp+b-(skip%b)<n){
		tmp2=n-tmp-b+(skip%b);
		tmp+=(g*(tmp2/(g+b)))+min(g,tmp2%(g+b));
	}
	return (tmp>=n || 2*tmp>=n);
}

void solve(){
	long long n,g,b;
	cin>>n>>g>>b;
	if(g>=b){
		cout<<n<<"\n";
	}
	else{
		long long x=0,y=MOD*MOD;
		// cout<<y*2<<"\n";
		while(y-x>1ll){
			long long mid=(x+y)/2ll;
			if(tf(mid,g,b,n))
				y=mid;
			else
				x=mid;
		}

		if(tf(x,g,b,n))
			cout<<n+x<<"\n";
		else
			cout<<n+y<<"\n";
	}
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