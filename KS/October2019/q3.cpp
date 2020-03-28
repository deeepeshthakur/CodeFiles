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

bool get_h(std::vector<long long>& a, std::vector<long long>& b, int n, long long h, int m){
	long long ha = 0, hb = 0;
	for(int i = 0; i < n ; i++){
		if(m%3 != 1){
			ha += a[i];
		}

		if(m%3 != 0){
			hb += b[i];
		}
		m/=3;
	}

	return (ha >= h) && (hb >= h);
}

void solve(int tc){
	int n;
	long long h;
	std::cin >> n >> h;
	std::vector<long long> a(n,0ll), b(n,0ll);
	for(int i = 0; i < n; i++){
		std::cin >> a[i];
	}

	for(int i = 0; i < n; i++){
		std::cin >> b[i];
	}

	long long ctr = 0;
	if(n <= 12){
		int max_lim = 1;
		for(int i = 0; i < n; i++){
			max_lim *= 3;
		}

		for(int i = 0; i < max_lim; i++){
			if(get_h(a,b,n,h,i))
				ctr++;
		}

		std::cout << "Case #" << tc << ": " << ctr << "\n";
	}
	else{
		std::cout << "Case #" << tc << ": " << 1 << "\n";
	}
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