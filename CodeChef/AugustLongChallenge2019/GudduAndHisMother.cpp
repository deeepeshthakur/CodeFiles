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

void f1(int n, std::vector<int> &a, std::vector<int> &b){
	std::vector<int> tmp(n,0);
	int xr = 0;
	for(int i = 0; i < n; i++){
		xr = (xr^a[i]);
		tmp[i] = xr;
		a[i] = tmp[i];
	}
	
	std::sort(tmp.begin(),tmp.end());
	for(int i = 0; i < n; i++){
		if(i == 0 || tmp[i] != tmp[i-1]){
			b.push_back(tmp[i]);
		}
	}
}

void solve(){
	int n;
	std::cin >> n;
	std::vector<int> a(n,0), distinct_xor;
	for(int i = 0; i < n; i++){
		std::cin >> a[i];
	}
	f1(n, a, distinct_xor);
	int m = distinct_xor.size();

	std::vector<std::vector<int>> pre_cal(m);
	int xr = 0;
	for(int i = 0; i < n; i++){
		int ind = std::distance(distinct_xor.begin(),std::lower_bound(distinct_xor.begin(),distinct_xor.end(),a[i]));
		// std::cout << ind << " " << distinct_xor[ind] << " " << i + 1 << std::endl;
		pre_cal[ind].push_back(i+1);
	}

	long long ans = 0;
	for(int i = 0; i < m; i++){
		long long t = pre_cal[i].size();
		if(distinct_xor[i] == 0){
			for(int j = 0; j < t; j++){
				ans += (pre_cal[i][j] - 1);
			}
		}

		for(long long j = 1; j < t; j++){
			ans += (t-j)*(j)*(pre_cal[i][j] - pre_cal[i][j-1]);
		}
		ans += (t*(t-1)*(t-2))/6;
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