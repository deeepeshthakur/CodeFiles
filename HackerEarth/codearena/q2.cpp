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
	a = a%MOD;
	if(a == 0)
		return 0ll;
	if(b == 0)
		return 1ll;
	if(b == 1)
		return a%MOD;
	long long x = pow_mod(a,b/2)%MOD;
	return ((b%2 == 1) ? (((x*x)%MOD)*a)%MOD : (x*x)%MOD);
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

void print_vec(vector<long long>& a){
	for(int i=0;i<a.size();i++)
		cout << a[i] << (i<a.size()-1 ? " ":"\n");
}

// void solve_kick_start(int test_case){

// }

long long ncr(int n,int r,vector<long long>& fac){
	if(n < 0 || n < r || r < 0)
		return 0ll;
	if(n == r || r == 0)
		return 1ll;
	r = min(n-r,r);
	if(r == 1)
		return n%MOD;

// 	return (ncr(n-1,r)+ncr(n-1,r+1))%MOD;
    long long num=fac[n]%MOD,den=(fac[r]*fac[n-r])%MOD;
    return (num*(pow_mod(den,MOD-2)%MOD))%MOD;
}

void solve(){
	long long n,r;
	cin >> n >> r;
	vector<long long> fac(1000,1ll);
	for(int i=2;i<1000;i++){
		fac[i] = (fac[i-1]*(1ll*i))%MOD;
	}
	// print_vec(fac);
	long long ans;
	if(n < r || n-1 < n-r || n-r < 0 || n-1 < 0){
		ans = -1ll;
	}
	else{
		ans = ncr(n-1,n-r,fac);
	}
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
	solve();

	// // Kick Start Template	
	// int test_cases;
	// cin >> test_cases;
	// for(int i=1;i<=test_cases;i++){
	// 	solve_kick_start(i);
	// }

	return 0;
}