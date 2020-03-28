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
const long long MOD=1e18+7;

void solve(){
	int t = 10;
	std::cout << t << std::endl;
	long long n = 5000, m = 1e9;
	while(t--)
		std::cout << rand()%m + 1 << " " << rand()%n + 1 << " " << rand()%m + 1 << std::endl;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	srand(time(0));
	// int t;
	// std::cin >> t;
	// while(t--){
	// 	solve();
	// }

	solve();
	// std::cout << int(1e3) << std::endl;
	// long long p2 = 1;
	// for(int i = 0; i < int(1e5); i++){
	// 	std::cout << p2 << std::endl;
	// 	p2 *= 2;
	// 	p2 %= MOD;
	// }
	return 0;
}