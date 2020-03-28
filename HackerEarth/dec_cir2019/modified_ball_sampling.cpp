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

void get_binary(int n, vector<int>& a){
	while(n){
		a.pb(n%2);
		n/=2;
	}
}

void solve(){
	int n,p,k;
	cin>>n>>p>>k;
	vector<int> binary_k;
	get_binary(k,binary_k);
	vector<long long> curr(p,0ll),next(p,0ll),ans_p(p,0ll);
	ans_p[1]=1;
	for(int i=0,tmp;i<n;i++){
		cin>>tmp;
		curr[tmp]++;
	}

	for(int curr_bit=0;curr_bit<binary_k.size();curr_bit++){
		if(curr_bit>0){
			for(int i=1;i<p;i++){
				next[(1ll*i*i)%p] += (curr[i]*curr[i])%MOD;
				for(int j=i+1;j<p;j++){
					next[(1ll*i*j)%p] += 2ll*((curr[i]*curr[j])%MOD);
				}
			}

			for(int i=1;i<p;i++){
				curr[i]=next[i]%MOD;
				next[i]=0;
			}
		}

		if(binary_k[curr_bit]==1){
			for(int i=1;i<p;i++)
				for(int j=1;j<p;j++)
					next[(1ll*i*j)%p]+=(ans_p[i]*curr[j])%MOD;


			for(int i=1;i<p;i++){
				ans_p[i]=next[i]%MOD;
				next[i]=0;
			}
		}	
	}

	long long ans=0;
	for(int i=1;i<p;i++){
		ans+=(ans_p[i]*i)%MOD;
		ans%=MOD;
	}

	ans=(ans*pow_mod(pow_mod(n*1ll,k*1ll),MOD-2))%MOD;
	cout<<ans<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}