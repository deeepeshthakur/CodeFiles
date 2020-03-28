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

void print_vec(std::vector<long long>& a){
	for(int i=0;i<a.size();i++)
		std::cout << a[i] << (i+1<a.size() ? " ":"\n");
}

void solve(){
	long long n;
	std::cin >> n;
	// std::vector<bool> fac(int(1e6)+1,0ll);
	long long l = std::min((long long)(1e6)+1,n);
	std::set<long long> fac_set;
	for(int i=2;i<l;i++){
		if(n%i==0){
			fac_set.insert(1ll*i);
			fac_set.insert(n/i);
		}
	}
	fac_set.insert(n);

	std::vector<long long> fac(fac_set.size(),0ll);
	int j=0;
	for(auto i=fac_set.begin();i!=fac_set.end();i++){
		fac[j] = *i;j++;
	}

	long long gcd_arr = fac[0];
	for(int i=0;i<fac.size();i++)
		gcd_arr = __gcd(gcd_arr,fac[i]);

	std::cout << gcd_arr << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	// int t;
	// std::cin >> t;
	// while(t--){
	// 	solve();
	// }

	solve();
	return 0;
}