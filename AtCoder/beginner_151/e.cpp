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

long long ncr(int n, int r, vector<long long>& fact){
	if(n>=0 && r>=0 && n>=r){
		long long ans=(fact[n-r]*fact[r])%MOD;
		return (fact[n]*pow_mod(ans,MOD-2))%MOD;
	}
	return 0ll;
}

long long get_f(int m, int n, vector<long long>& fact, int k){
	long long ans=MOD;
	ans+=(ncr(m-1,k+1,fact)-ncr(n-m,k+1,fact)+MOD);
	return ans%MOD;
}

void solve(){
	int n,k;
	cin>>n>>k;
	vector<long long> a(n,0ll),fact(n+100,1ll);
	for(int i=1;i<fact.size();i++)
		fact[i]=(fact[i-1]*i)%MOD;

	// cout<<ncr(4,2,fact)<<" " << ncr(4,1,fact)<<" " <<ncr(4,0,fact)<<"\n";

	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(full(a));
	if(k==1){
		cout<<0<<"\n";
		return;
	}

	long long ans=0ll;
	for(int i=0;i<n;i++)
		ans+=(((a[i]+MOD)%MOD)*get_f(i+1,n,fact,k-2))%MOD;
	ans%=MOD;
	cout<<ans<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}