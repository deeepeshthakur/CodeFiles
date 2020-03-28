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

// long long f1(long long a){
// 	long long ans=0;
// 	if(a%2==0){
// 		ans=a/2;
// 		a=a+MOD-1;
// 		ans%=MOD;
// 		a%=MOD;
// 		ans=(a*ans)%MOD;
// 	}
// 	else{
// 		ans=(a-1)/2;
// 		ans%=MOD;
// 		a%=MOD;
// 		ans=(a*ans)%MOD;
// 	}
// 	return ans;
// }

// long long f2(long long a, long long b){
// 	if(a<=b){
// 		if(a%2!=b%2){
// 			return ((b-a+1)/2)%MOD;
// 		}
// 		else{
// 			return ((b-a+1+(a%2==0?1:-1))/2)%MOD;
// 		}
// 	}
// 	return 0ll;
// }

void solve(){
	long long l,r;
	cin>>l>>r;
	long long pw2=1,tmpl=l,ans=0;
	while(pw2<=r){
		if(tmpl%2==1){
			long long tmp=l/pw2;
			if(((l+1)/pw2)%2==0)
				tmp=l;
			else
				tmp=min((tmp+1)*pw2,r);
			ans+=((pw2%MOD)*((tmp-l+1)%MOD))%MOD;
			ans%=MOD;
		}
		cout<<tmpl<<" "<<pw2<<" "<<ans<<"\n";
		tmpl/=2ll;
		pw2*=2ll;
	}
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