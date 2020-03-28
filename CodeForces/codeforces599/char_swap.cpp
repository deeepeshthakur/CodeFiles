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
	std::string s,t;
	std::cin >> s;
	std::cin >> t;

	std::vector<int> diff_ind;
	for(int i=0;i<n;i++){
		if(s[i] != t[i]){
			diff_ind.pb(i);
		}
	}

	if(diff_ind.size() == 0){
		std::cout << "Yes\n";
		return;
	}

	if(diff_ind.size() == 2){
		std::swap(s[diff_ind[0]],t[diff_ind[1]]);
		if(s[diff_ind[0]] == t[diff_ind[0]] && s[diff_ind[1]] == t[diff_ind[1]]){
			std::cout << "Yes\n";
			return;
		}
	}
	std::cout << "No\n";
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