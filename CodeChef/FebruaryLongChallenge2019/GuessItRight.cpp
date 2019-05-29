#include<bits/stdc++.h>
#define iint int
#define pll std::pair<iint,iint>
#define rep(i,a,b) for(iint i=(iint)a;i<(iint)b;i++)
#define per(i,a,b) for(iint i=(iint)a;i>(iint)b;i--)
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

long long f101(long long a,long long b){
	if(a==0) return 0ll;
	if(b==0) return 1ll;
	if(b==1) return a%MOD;

	long long x=f101(a,b/2);
	x*=x;
	x%=MOD;
	if(b%2){
		return (x*a)%MOD;
	}
	return x;
}

void f100(){
	long long n,m,k;
	std::cin>>n>>k>>m;
	if(k==2){
		std::cout<<1<<"\n";
		return;
	}

	if(n==1){
		std::cout<<1<<"\n";
		return;
	}

	long long p=1,q=1,ans;
	if(m%2){
		p=(f101(n,(m+1)/2)-f101(n-1,(m+1)/2)+MOD)%MOD;
		q=f101(f101(n,(m+1)/2)%MOD,MOD-2);
		ans = (p*q)%MOD;
	}
	else{
		m=m/2;
		p=(((n+k)*((f101(n,m)-f101(n-1,m)+MOD)%MOD))%MOD + f101(n-1,m)%MOD)%MOD;
		q=f101(((n+k)*f101(n,m))%MOD,MOD-2);
		ans=(p*q)%MOD;
	}
	std::cout<<ans<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int t;
	std::cin>>t;
	while(t--){
		f100();
	}
	return 0;
}