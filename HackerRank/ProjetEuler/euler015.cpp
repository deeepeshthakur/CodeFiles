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

void solve(){
	long long n,m;
	cin>>n>>m;
	vector<long long> fact(int(m+n)+1,1ll);
	for(int i=1;i<fact.size();i++)
		fact[i]=(fact[i-1]*i)%MOD;
	cout<<(fact[m+n]*pow_mod((fact[n]*fact[m])%MOD,MOD-2))%MOD<<"\n";
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