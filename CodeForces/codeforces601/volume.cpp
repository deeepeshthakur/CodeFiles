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
	long long a,b;
	cin >> a >> b;
	if(a > b){
		std::swap(a,b);
	}

	int ans = 0;
	ans += (b-a)/5;
	b -= 5*((b-a)/5);

	ans += (b-a)/2;
	b -= 2*((b-a)/2);

	ans += b-a;
	cout << ans <<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	// CodeChef Template
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