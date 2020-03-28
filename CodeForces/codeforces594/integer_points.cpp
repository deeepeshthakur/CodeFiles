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
	int n,m;
	std::cin >> n;
	std::vector<long long> n_arr(n,0ll);
	for(int i = 0; i < n; i++){
		std::cin >> n_arr[i];
	}

	std::cin >> m;
	std::vector<long long> m_arr(m,0ll);
	for(int i = 0; i < m; i++){
		std::cin >> m_arr[i];
	}

	long long ans = 0, a = 0, b = 0, c = 0, d = 0;
	for(int i = 0; i < n; i++){
		if(n_arr[i]%2 == 1){
			a++;
		}
		else{
			b++;
		}
	}

	for(int i = 0; i < m; i++){
		if(m_arr[i]%2 == 1){
			c++;
		}
		else{
			d++;
		}
	}

	ans = a*c + b*d;
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