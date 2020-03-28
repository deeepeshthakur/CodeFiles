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

double f1(int a, int b){
	return 1.0*(std::abs(a-b))/2;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,l;
	std::cin >> n >> l;
	std::vector<int> grid(n,0);
	for(int i = 0; i < n; i++){
		std::cin >> grid[i];
	}

	std::sort(full(grid));
	double ans = 0.0;
	ans = std::max(grid[0],l - grid[n-1])*1.0;
	for(int i = 0; i + 1 < n; i++){
		ans = std::max(ans,f1(grid[i],grid[i+1]));
	}

	std::cout << std::fixed << std::setprecision(11) << ans << std::endl;
	return 0;
}