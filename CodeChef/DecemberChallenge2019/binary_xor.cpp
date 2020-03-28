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

long long pow_mod(long long a, long long b){
	if(a == 0)
		return 0ll;
	if(b == 0)
		return 1ll;
	if(b == 1)
		return a%MOD;
	long long x = pow_mod(a,b/2);
	x = (x*x)%MOD;
	if(b%2==1)
		return (x*a)%MOD;
	return x;
}

long long nCr(int n, int r, vector<long long>& fact){
	if(n<0 || r<0 || n<r)
		return 0ll;
	return (fact[n]*pow_mod((fact[n-r]*fact[r])%MOD,MOD-2))%MOD;
}

void solve(){
	int n;
	cin>>n;
	string str_a,str_b;
	vector<long long> factorial_i(n+1,1ll);
	for(int i=1;i<=n;i++)
		factorial_i[i]=(factorial_i[i-1]*i)%MOD;
	cin>>str_a>>str_b;
	int x=0,y=0;
	for(int i=0;i<n;i++){
		x+=(str_a[i]=='1' ? 1:0);
		y+=(str_b[i]=='1' ? 1:0);
	}

	if(true){
		int t1,t2;
		t1=min(x,y);
		t2=min(n-x,n-y);
		x=t1;
		y=t2;
	}
	long long ans=0;
	for(int i=0;i<=min(x,y);i++)
		ans=(ans+nCr(n,n-x-y+2*i,factorial_i))%MOD;
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