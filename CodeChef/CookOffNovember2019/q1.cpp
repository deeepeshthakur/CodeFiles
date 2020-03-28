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
	int n;
	std::cin >> n;
	std::vector<long long> x(n,0ll), h(n,0ll);
	for(int i=0;i<n;i++)
		std::cin >> x[i] >> h[i];
	std::vector<long long> del{abs(x[0]-x[1]),abs(x[n-1]-x[n-2])};
	for(int i=1;i<n-1;i++){
		del.pb(abs(x[i]-x[i-1])+abs(x[i+1]-x[i]));
	}
	std::sort(full(del));
	std::sort(full(h));
	long long ans=0;
	for(int i=0;i<n;i++){
		ans += h[i]*del[i];
	}
	std::cout << ans << "\n";
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

	// 	solve();
	return 0;
}