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

void solve(){
	
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

	// 	solve();
	// long long max = (1e9);
	// max *= (max/1000);
	std::cout << 1 << "\n";
	int n = rand()%50;
	std::cout << n << " " << 200 << "\n";
	for(int i = 0 ; i < n; i++){
		std::cout << rand()%101 << " ";
	}
	std::cout << "\n";
	return 0;
}