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

bool f1(int a,int b, int c){
	return (c%__gcd(a,b) == 0);
}

void solve(int tc){
	int a,b,c;
	std::cin >> a >> b >> c;
	std::cout << "Case " << tc << ": " << (f1(a,b,c) ? "Yes" : "No") << "\n";
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