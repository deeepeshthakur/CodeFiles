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

double f2(long long d,long long x){
	return 1.0*x+(1.0*d/(x+1));
}

bool tf(long long x, long long d){
	return f2(d,x)>f2(d,x+1);
}

long long f3(long long d, long long x){
	return (long long)(ceil(f2(d,x)));
}

long long f1(long long d, long long n){
	long long l=0,r=n;
	while(r-l>1){
		long long mid=(l+r)/2;
		// cout<<mid << " " << f2(d,mid) << " " <<f2(d,mid+1)<<"\n";
		if(tf(mid,d)){
			l=mid;
		}
		else{
			r=mid;
		}
	}
	return min(f3(d,l),f3(d,r));
}


void solve(){
	long long n,d;
	cin>>n>>d;
	// if(d<=n){
	// 	cout<<"YES\n";
	// 	return;
	// }
	if(f1(d,n)<=n){
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int t=1;       
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}