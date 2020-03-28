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

long long pow_c(long long a, long long b){
	if(a == 0)
		return 0ll;
	
	if(b == 0)
		return 0ll;

	if(b == 1)
		return a;

	long long x = pow_c(a,b/2);
	if(b%2 == 1){
		return x*x*a;
	}

	return x*x;
}

bool is_power_k(long long a, int k){
	long long l = 1, r = (int)(std::pow(1.0*a,1.0/(1.0*k)))+2, mid;
	while(r-l > 1){
		mid = (r+l)/2;
		if(pow_c(mid,k) > a)
			r = mid;
		else
			l = mid;
	}

	return (pow_c(l,k) == a) || (pow_c(r,k) == a);
}

int get_power(int a, int b){
	if(b%2 == 1)
		return a;
	return 1;
}

int get_power3_9(int a, int b){
	int ans = 1;
	while(b > 0){
		ans *= a;
		b--;
	}
	return ans;
}

std::vector<int> primes;

void get_primes(){
	int n = int(1e5)+1;
	std::vector<bool> chk(int(1e5)+1,true);
	chk[0]=false;
	chk[1]=false;
	for(int i=0;i<n;i++){
		if(chk[i]){
			int j = i;
			while(1ll*j*i < n){
				chk[j*i]=false;
				j++;
			}
		}
	}

	for(int i=0;i<n;i++){
		if(chk[i])
			primes.pb(i);
	}
}

void solve(){
	get_primes();
	long long n, k;
	std::vector<int> arr(int(1e5)+1,0);
	for(int i=0;i<n;i++){
		int a;
		std::cin >> a;
		arr[a]++;
	}

	std::vector<std::vector<std::pair<int,int>>> factors(int(1e5)+1);
	factors[1].pb({1,1});

	for(int i=0;i<primes.size();i++){
		int fac=primes[i];
		factors[fac].pb({fac,1});
		for(int j=2;j*fac<factors.size();j++){
			int num = j*fac;
			int cnt = 0;
			while(num%fac == 0){
				cnt++;
				num /= fac;
			}

			factors[j*fac].pb({fac,cnt});
		}
	}

	long long ans = 0ll;

	if(k == 2){
		std::vector<long long> nums(int(1e5)+1,-1ll);
		int num = 1;
		for(int i=0;i<factors.size();i++){
			num = 1;
			for(int j=0;j<factors[i].size();j++){
				num *= get_power(factors[i][j].F, factors[i][j].S);
			}
			nums[num]++;
		}

		for(int i=0;i<nums.size();i++){
			if(nums[i] > 0)
				ans += (nums[i]*(nums[i]+1))/2;
		}
	}

	if(k > 2 && k < 10){
		std::vector<long long> nums(int(1e5)+1,-1ll);
		int num = 1;
		for(int i=0;i<factors.size();i++){
			num = 1;
			for(int j=0;j<factors[i].size();j++){
				num *= get_power3_9(factors[i][j].F, factors[i][j].S%k);
			}
			nums[num]++;
		}

		for(int i=0;i<nums.size();i++){
			if(nums[i] > 0){

			}
		}

	}

	if(k >= 10){

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