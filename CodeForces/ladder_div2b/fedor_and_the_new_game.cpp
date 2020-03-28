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

bool f2(std::vector<std::vector<bool>>& v, int ind, int n, int m, int k){
	int ctr = 0;
	for(int i = 0; i < n; i++){
		ctr += (v[ind][i]^v[m][i] ? 1 : 0);
	}

	return ctr <= k;
}

void f1(std::vector<std::vector<bool>>& v, int ind, int n, int x){
	for(int i = 0; i < n; i++){
		v[ind][i] = (x%2 == 1);
		x /= 2;
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,m,k;
	std::cin >> n >> m >> k;
	std::vector<std::vector<bool>> grid(m+1,std::vector<bool>(n,false));
	for(int i = 0; i < m + 1; i++){
		int x;
		std::cin >> x;
		f1(grid, i, n, x);
	}

	int ans = 0;
	for(int i = 0; i < m; i++){
		ans += (f2(grid, i, n, m, k) ? 1 : 0);
	}
	std::cout << ans << std::endl;
	return 0;
}