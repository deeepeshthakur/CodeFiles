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

void print_vec(std::vector<int>& a){
	for(int i = 0; i < a.size(); i++){
		std::cout << a[i] << (i < a.size() - 1 ? " ": "\n");
	}
}

void get_binary(std::vector<int>& a, long long n){
	int i = 0;
	while(n){
		a[i] += n%2;
		n/=2;
		i++;
	}
}

long long get_min_m(std::vector<int>& a, int n){
	long long ans = 0,mul = 1;
	for(int i = 0; i < a.size(); i++){
		ans += (1ll*std::min(a[i],n-a[i]))*mul;
		mul *= 2ll;
	}
	return ans;
}

long long get_m(std::vector<int>& a, long long k, int n){
	long long ans = 0, mul = 1;

	for(int i = 0; i < a.size(); i++){
		if(k%2 == 1){
			ans += mul*((n-a[i])*1ll);
		}
		else{
			ans += mul*(a[i]*1ll);
		}
		k /= 2;
		mul	*= 2;
	}
	return ans;
}

void solve(int tc){
	int  n;
	long long m;
	std::cin >> n >> m;
	std::vector<long long> arr(n,0ll);
	for(int i = 0; i < n; i++){
		std::cin >> arr[i];
	}

	std::vector<int> binary_sum(40,0);
	for(int i = 0; i < n; i++){
		get_binary(binary_sum,arr[i]);
	}

	// print_vec(binary_sum);

	long long min_m = get_min_m(binary_sum,n);
	// std::cout << min_m << "    ";
	
	if(min_m > m){
		std::cout << "Case #" << tc << ": " << -1 << "\n";
		return; 
	}

	if(m == 0){
		std::cout << "Case #" << tc << ": " << arr[0] << "\n";
		return;
	}

	// long long k1 = 0, k2 = 0,tmp;
	// for(int i = 28; i >= 0; i--){
	// 	tmp = (1ll << i);
	// 	if(get_m(binary_sum,k1+tmp,n) <= m){
	// 		k1 += tmp;
	// 	}
	// }

	// for(int i = 0; i <= 30; i++){
	// 	tmp = (1ll << i);
	// 	if(get_m(binary_sum,k1+tmp,n) <= m){
	// 		k2 += tmp;
	// 	}
	// }
	// // std::cout << "Case #" << tc << ": " << k1  <<"\n";

	// std::cout << "Case #" << tc << ": " << std::max(k1,k2) << "\n";

	long long mk = 0ll;
	for(long long i = 0; i <= 400; i++){
		if(m >= get_m(binary_sum,i,n)){
			mk = i;
		}
	}
	std::cout << "Case #" << tc << ": " << mk << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int t;
	std::cin >> t;
	for(int i = 1; i <= t; i++){
		solve(i);
	}

	// 	solve();
	return 0;
}