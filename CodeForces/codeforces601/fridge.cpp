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
// #define cin std::cin
// #define cout std::cout
// #define vector std::vector
// #define pair std::pair

using namespace std;
const double pi=acos(-1.0);
const double pii=2*pi;
const double eps=1e-6;
const long long MOD=1e9+7;

// void print_vec(std::vector<int>& a){
// 	for(int i=0;i<a.size();i++)
// 		std::cout << a[i] << (i<n-1 ? " ":"\n");
// }

// void print_vec(std::vector<long long>& a){
// 	for(int i=0;i<a.size();i++)
// 		std::cout << a[i] << (i<n-1 ? " ":"\n");
// }

// void solve_kick_start(int test_case){

// }

void solve(){
	int n,m;
	std::cin >> n >> m;
	std::vector<std::pair<int,int>> a(n,{0,0});
	for(int i=0;i<n;i++){
		std::cin >> a[i].F;
		a[i].S = i+1;
	}

	std::sort(full(a));

	if(n == 2 || m < n){
		std::cout << "-1\n";
		return;
	}

	int max_cost = m * (a[0].F + a[1].F);
	std::vector<std::pair<int,int>> ans(m,{a[0].S,a[1].S});
	for(int i=0;i<n;i++){
		ans[i].F = a[i].S;
		ans[i].S = a[(i+1)%n].S;
		max_cost += (a[i].F + a[(i+1)%n].F - a[0].F - a[1].F);
	}
	std::cout << max_cost << "\n";
	for(int i=0;i<m;i++)
		std::cout << ans[i].F << " " << ans[i].S << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	// // CodeChef Template
	int t;       
	std::cin >> t;
	while(t--){
		solve();
	}

	// // Single test case input
	// solve();

	// // Kick Start Template	
	// int test_cases;
	// std::cin >> test_cases;
	// for(int i=1;i<=test_cases;i++){
	// 	solve_kick_start(i);
	// }


	return 0;
}