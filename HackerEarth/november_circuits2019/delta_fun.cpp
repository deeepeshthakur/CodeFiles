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
	if(a == 0ll)
		return 0ll;
	if(b == 0ll)
		return 1ll;
	if(b == 1ll)
		return a%MOD;
	long long x = pow_mod(a,b/2)%MOD;
	x = (x*x)%MOD;
	if(b%2 == 1)
		return (x*(a%MOD))%MOD;
	return x%MOD;
}

// long long pow_int(long long a, long long b){
// 	if(a==0)
// 		return a;
// 	if(b==0)
// 		return 1;
// 	if(b==1)
// 		return a;
// 	long long x = pow_int(a,b/2);
// 	return ((b%2 == 1) ? x*x*a : x*x);
// }

// int pow_int(int a, int b){
// 	if(a==0)
// 		return a;
// 	if(b==0)
// 		return 1;
// 	if(b==1)
// 		return a;
// 	int x = pow_int(a,b/2);
// 	return ((b%2 == 1) ? x*x*a : x*x);
// }


// void print_vec(vector<int>& a){
// 	for(int i=0;i<a.size();i++)
// 		cout << a[i] << (i<n-1 ? " ":"\n");
// }

// void print_vec(vector<long long>& a){
// 	for(int i=0;i<a.size();i++)
// 		cout << a[i] << (i<n-1 ? " ":"\n");
// }

// void solve_kick_start(int test_case){

// }

vector<vector<int>> fact(int(1e6)+1);
// vector<vector<long long> powrs(int(1e6)+1);
vector<bool> primes(int(1e6)+1,true);
vector<long long> dp(int(1e6)+1);

inline long long f3(long long n){
	return ((n*(n+1))/2)%MOD;
}

inline long long get_ap(long long a, long long n){
	return (f3(n)*a)%MOD;
}

long long f1(int ind){
	long long ans=0;
	vector<pair<long long,int>> mul{{1ll,1}};
	for(int i=0;i<fact[ind].size();i++){
		int k = mul.size();
		for(int j=0;j<k;j++){
			mul.pb({mul[j].F*fact[ind][i],-1*mul[j].S});
		}
	}

	for(int i=1;i<mul.size();i++){
		ans = (ans + MOD + mul[i].S*get_ap(mul[i].F,(1ll*ind)/mul[i].F))%MOD;
	}
	return ans;
}

void pre_c(){	
	int n=1e6+1;
	primes[0]=false;
	primes[1]=false;
	long long tmp,mul;
	for(int i=0;i<n;i++){
		if(primes[i]){
			fact[i].pb(i);
			int j=2;
			while(i*j < n){
				primes[i*j]=false;
				fact[i*j].pb(i);
				j++;
			}
		}
	}
	dp[1] = 1;
	for(int i=2;i<dp.size();i++){
		dp[i] = (f3(1ll*i) + f1(i) + MOD)%MOD;
		dp[i] = (dp[i-1] + (2ll*i)*dp[i])%MOD;
	}
} 


void solve(){
	long long n;
	cin >> n;
	long long ans = 0;
	for(auto lcf=1;lcf<=n;lcf++)
		ans = (ans+dp[int(n/lcf)])%MOD;

	cout << ans << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	// // CodeChef Template
	// int t;       
	// cin >> t;
	// while(t--){
	// 	solve();
	// }

	// Single test case input
	pre_c();
	solve();

	// // Kick Start Template	
	// int test_cases;
	// cin >> test_cases;
	// for(int i=1;i<=test_cases;i++){
	// 	solve_kick_start(i);
	// }

	return 0;
}