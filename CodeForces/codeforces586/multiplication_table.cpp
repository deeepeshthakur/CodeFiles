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

long long gcd_t(long long a, long long b){
	if(a > b)
		return gcd_t(b,a);

	if(a == 0)
		return b;

	return gcd_t(a,b%a);
}

long long gcd_vec(std::vector<long long>& a, int l, int r){
	if(r - l <= 1){
		return gcd_t(a[l],a[r]);
	}
	return gcd_t(gcd_vec(a,l,(l+r)/2),gcd_vec(a,(l+r)/2+1,r));
}

void get_fac(long long num, std::vector<long long>& a){
	a.resize(0);
	for(long long i = 1; i*i <= (long long)(1e9); i++){
		if(num%i == 0){
			a.push_back(i);
			a.push_back(num/i);
		}
	}
	std::sort(full(a));
}

bool f1(long long a, std::vector<long long>& ans, std::vector<std::vector<long long>>& grid){
	ans[0] = a;
	for(int i = 1; i < ans.size(); i++){
		ans[i] = grid[0][i]/a;
	}

	for(int i = 0; i < grid.size(); i++){
		for(int j = 0; j < grid[0].size(); j++){
			if(j != i){
				if(grid[i][j] != ans[i]*ans[j]){
					ans[0] = -1;
					return false;
				}
			}
		}
	}
	return true;
}

void solve(){
	int n;
	std::cin >> n;
	std::vector<std::vector<long long>> grid(n,std::vector<long long>(n,0ll));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			std::cin >> grid[i][j];
		}
	}

	long long a1 = gcd_vec(grid[0],0,n-1);
	std::vector<long long> fans(n,1ll), fact_a0;
	get_fac(a1,fact_a0);

	bool flag = true;
	for(int i = 0; i < fact_a0.size() && flag; i++){
		flag = !(f1(fact_a0[i],fans,grid));
	}

	if(fans[0] != -1){
		for(int i = 0; i < fans.size(); i++){
			std::cout << fans[i] << (i + 1 < n ? " " : "\n");
		}
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