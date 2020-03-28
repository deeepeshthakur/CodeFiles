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

std::vector<std::vector<long long>> dp_table(51,std::vector<long long>(51,-1ll));

long long f1(int i, int j){
	if(j > i || i < 0 || j < 0)
		return 0ll;

	if(j == 0 || i == j)
		return 1ll;

	return dp_table[i-1][j] + dp_table[i-1][j-1]; 
}

void f0(){
	for(int i = 0;i < 51; i++){
		for(int j = 0; j < 51; j++){
			dp_table[i][j] = f1(i,j);
		}
	}
}

void solve(){
	int n,k;
	std::cin >> n >> k;
	std::vector<int> a(n,0);

	for(int i = 0; i < n; i++){
		std::cin >> a[i];
	}

	std::sort(full(a));

	long long ctr = 0ll, ctrk = 0ll;
	for(int i = 0; i < n; i++){
		if(a[i] < a[k-1])
			ctr++;

		if(a[i] == a[k-1])
			ctrk++;
	}

	std::cout << dp_table[ctrk][k - ctr] << std::endl;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	f0();

	int t;
	std::cin >> t;
	while(t--){
		solve();
	}

	// 	solve();
	return 0;
}