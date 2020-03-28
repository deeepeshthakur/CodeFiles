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

long long pow_mod(long long a, long long b){
	if(b == 0)
		return 1ll;
	if(a == 0)
		return 0ll;
	if(b == 1)
		return a%MOD;
	long long x = pow_mod(a,b/2);
	x = (x*x)%MOD;
	if(b%2==1)
		return (x*a)%MOD;
	return x;
}

void solve(){
	long long n,m,k;
	cin>>n>>m>>k;
	vector<long long> prev(k+1,0),next(k+1,0);
	prev[0]=1;
	for(int j=0;j<k;j++){
		for(int i=0;i<=j+1;i++){
			if(prev[i]>0){
				next[i]+=(prev[i]*i)%MOD;
				next[i+1]+=((prev[i]*(n-i))%MOD);
			}
		}
		for(int i=0;i<=j+1;i++){
			prev[i]=next[i]%MOD;
			next[i]=0;
		}
	}
	long long ans=0,pow_m=1;
	for(int i=0;i<prev.size();i++){
		ans+=(prev[i]*pow_mod(pow_m,MOD-2))%MOD;
		ans%=MOD;
		pow_m=(pow_m*m)%MOD;
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