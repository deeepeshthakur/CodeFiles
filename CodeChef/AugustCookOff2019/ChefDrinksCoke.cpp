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

int f2(int del, int tim){
	if(del > tim){
		return del - tim;
	}

	return 0;
}

int f1(int curr, int abm, int tim){
	if(curr == abm){
		return abm;
	}

	if(curr > abm)
		return abm + f2(curr - abm, tim);

	return abm - f2(abm - curr, tim);
}

void solve(){
	int n,m,k,l,r;
	std::cin >> n >> m >> k >> l >> r;
	std::vector<std::vector<int>> Vec(n, std::vector<int>(2,0));
	for(int i = 0; i < n; i++){
		std::cin >> Vec[i][1] >> Vec[i][0];
	}

	std::sort(Vec.begin(),Vec.end());

	int ans = -1;
	bool flag = true;
	for(int i = 0; i < n && flag; i++){
		int c = Vec[i][1], p = Vec[i][0];
		c = f1(c, k, m);
		if(c <= r && c >= l){
			flag = false;
			ans = p;
		}
	}

	std::cout << ans << std::endl;

}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int t;
	std::cin >> t;
	while(t--){
		solve();
	}
	return 0;
}