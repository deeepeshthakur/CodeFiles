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

long long f1(int a, int b, int n){
	if(b < a){
		return 1ll*(n - a + b);
	}
	return 1ll*(b - a);
}

void solve(){
	int n,m;
	std::cin >> n >> m;
	std::vector<int> arr(m,0);
	for(int i = 0; i < m; i++){
		std::cin >> arr[i];
	}

	long long ans = 0;
	int curr = 1;
	for(int i = 0; i < m; i++){
		ans += f1(curr, arr[i], n);
		curr = arr[i];
	}

	std::cout << ans << std::endl;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}