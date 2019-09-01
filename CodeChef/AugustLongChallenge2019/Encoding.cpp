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

long long f1(long long a, long long b){
	if(a == 0ll)
		return 0ll;

	if(b == 0)
		return 1ll;

	if(b == 1ll)
		return a%MOD;

	long long ans = f1(a,b/2)%MOD;
	if(b%2){
		ans = (ans*a)%MOD;
	}

	return ans;
}

void solve(){
	long long l,r, ans = 0ll;
	std::string nl, nr;
	std::cin >> l >> nl;
	std::cin >> r >> nr;

	for(int i = 0; i < l; i++){
		if(i == 0 || nl[i] != nl[i-1]){
			ans += (1ll*int(nl[i] - '0')*f1(10ll,1ll*(l-1-i)))%MOD;
		}
	}

	for(int i = 0; i < r; i++){
		if(i == 0 || nr[i] != nr[i-1]){
			ans += (1ll*int(nr[i] - '0')*f1(10ll,1ll*(r-1-i)))%MOD;
		}
	}

	std::cout << ans << std::endl;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int t;
	std::cin >> t;
	while(t--){
		solve();
	}
	return 0;
}