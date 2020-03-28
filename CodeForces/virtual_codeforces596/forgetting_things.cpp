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
	int da, db;
	std::cin >> da >> db;
	if(da == db){
		std::cout << da << "91 " << db << "92\n";
		return; 
	}

	if(db - da == 1){
		std::cout << da << "99 " << db << "00\n";
		return;
	}

	if(da == 9 && db == 1){
		std::cout << da << "9 " << db << "00\n";
		return;
	}

	std::cout << "-1\n";

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