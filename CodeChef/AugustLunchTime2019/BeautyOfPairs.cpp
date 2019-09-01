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

void solve(){
	int n;
	std::cin >> n;
	std::vector<long long> w_vec(n-1,0ll), A_vec(n-1,0ll);
	std::vector<std::vector<long long>> p_vec(n-1,std::vector<long long>(2,0ll));
	std::vector<int> in_vec, out_vec, un_vec;
	for(int i = 0; i < n - 1; i++){
		if(p_vec[i][0] > p_vec[i][1]){
			out_vec.push_back()
		}
	} 
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