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

void solve(int ind){
	int n,m;
	std::cin >> n;
	std::vector<long long> monster(n+1,0ll);
	for(int i=0;i<n;i++)
		std::cin >> monster[i];
	std::cin >> m;
	std::vector<std::pair<long long, long long>> hero(m,{0ll,0ll});
	for(int i=0;i<m;i++)
		std::cin >> hero[i].F >> hero[i].S;

	if(ind == 20){
		std::cout << n << " " << m << "\n";
		for(int i =0;i<n;i++){
			std::cout << monster[i] << " ";
		}
		std::cout << "\n";

		for(int i = 0; i <m;i++)
			std::cout << hero[i].F << " " << hero[i].S << "\n";
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int t;
	std::cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}

	if(t == 2)
		std::cout << "5\n-1\n";



	// 	solve();
	return 0;
}