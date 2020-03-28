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

long long dis_log(long long r, long long b, long long p){
	long long n=(long long)(ceil(sqrt(p)));
	unordered_map<long long, long long> ht;
	long long pow_r=1ll;
	for(int i=0;i<n;i++){
		ht.insert({pow_r,i*1ll});
		pow_r=(pow_r*r)%p;
	}

	pow_r=pow_mod(r,p-1-n);
	for(int i=0;i<n;i++){
		if(ht.find(b)!=ht.end()){
			// cout<<ht.find(b)->second << " " << n << " " << i << "\n";
			return ((ht.find(b))->second)+i*n;
		}
		b=(b*pow_r)%p;
	}
	return -1ll;
}

void solve(){
	long long r,s,p,b;
	cin>>r>>s>>p;
	b=((s*(r-1))%p+1)%p;
	if(b==0)
		cout<<-1<<"\n";
	else if(b==1)
		cout<<p-1<<"\n";
	else{
		long long ans=dis_log(r,b,p);
		if(ans!=-1){
			ans%=p;
			cout<<ans<<"\n";
		}
		else
			cout<<ans<<"\n";
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