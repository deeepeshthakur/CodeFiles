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
const double MOD=1e9+7;

void solve(){
	int n;
	std::cin >> n;
	long long k,x,ans =0;
	std::vector<long long> a(n,0), delta(n,0);
	rep(i,0,n){
		std::cin >> a[i];
		ans += a[i];
	}

	std::cin >> k >> x;

	long long sum_delta = 0;
	rep(i,0,n){
		delta[i] = (a[i]^x) - a[i];
		sum_delta += delta[i];
	}

	sort(rfull(delta));

	// rep(i,0,n){
	// 	std::cout << delta[i] << " ";
	// }
	// std::cout << std::endl;
	// std::cout << ans << "   " << sum_delta << std::endl;
	if(k == n){
		if(sum_delta > 0){
			std::cout << ans + sum_delta << std::endl;
		}
		else{
			std::cout << ans << std::endl;
		}
		return;
	}
	int y = 0;
	while(y < n && delta[y] > 0){
		y++;
	}
	sum_delta = 0;
	rep(i,0,y){
		sum_delta += delta[i];
	}

	if(y == 0){
		std::cout << ans << std::endl;
		return;
	}

	long long diff_delta = - delta[y-1];
	if(y < n && (delta[y-1]+delta[y]) > 0){
		diff_delta = delta[y];
	}

	if(y%2 == 0){
		std::cout << ans + sum_delta << std::endl;
		return;
	}

	if(y >= k && k%2 == 1){
		std::cout<< ans + sum_delta << std::endl;
		return;
	}

	if(y < k){
		std::cout << ans + sum_delta + diff_delta << std::endl;
		return;
	}

	if(k%2 == 0){
		std::cout << ans + sum_delta + diff_delta << std::endl;
		return;
	}

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