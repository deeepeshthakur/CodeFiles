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

std::vector<int> ans_list;

void pre_calc(){
	int ind = 0;
	long double fac_val = 1.0;

	for(int i = 2; i <= int(1e6); i++){
		long double ld_i = i;
		fac_val /= (std::pow(i/(i-1.0),ind*1.0));
		while(fac_val <= 1.0){
			ind++;
			fac_val *= ((ind*1.0)/ld_i);
		}
		ans_list.push_back(ind);
	}
}

void solve(){
	int a;
	std::cin >> a;
	std::cout << ans_list[a-2] << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	pre_calc();
	int t;
	std::cin >> t;
	while(t--){
		solve();
	}

	// 	solve();
	return 0;
}