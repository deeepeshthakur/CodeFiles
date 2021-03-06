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

const int maxn = 1e5 + 10;
std::bitset<maxn> bit_set;

void solve(){
	int n, q;
	std::cin >> n >> q;
	bit_set[0] = 1;
	for(int i = 0; i < n; i++){
		int x;
		std::cin >> x;
		bit_set |= (bit_set << x);
	}

	std::vector<int> countr(maxn,0);
	countr[0] = 1;
	for(int i = 1; i < maxn; i++){
		countr[i] = countr[i-1] + bit_set[i];
	}

	int b,e;
	for(int i = 0; i < q; i++){
		std::cin >> b >> e;
		std::cout << countr[e] - countr[b-1] << "\n";
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
