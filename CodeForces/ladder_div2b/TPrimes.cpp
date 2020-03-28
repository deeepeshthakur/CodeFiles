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
		std::cout << a[i] << (i<a.size()-1? " ":"\n");
}

void get_primes(std::vector<long long>& primes){
	std::vector<bool> chk(int(2e6),true);
	chk[0] = false;
	chk[1] = false;

	for(int i=0;i<chk.size();i++){
		if(chk[i]){
			long long j=i;
			while(j*i<chk.size()){
				chk[j*i]=false;
				j++;
			}
		}
	}

	int k = 0;
	for(int i=0;i<chk.size();i++){
		if(chk[i] && k<primes.size()){
			primes[k]=i;
			k++;
		}
	}
}

void solve(){
	int n;
	std::cin >> n;
	std::vector<long long> inp(n,0);
	for(int i=0;i<n;i++)
		std::cin >> inp[i];

	std::vector<long long> primes(int(1e5),0ll), ans(int(1e5),0ll);
	
	get_primes(primes);

	for(int i=0;i<primes.size();i++){
		ans[i] = primes[i]*primes[i];
	}

	for(int i=0;i<n;i++){
		if(std::binary_search(full(ans),inp[i]))
			std::cout << "YES\n";
		else
			std::cout << "NO\n";
	}


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