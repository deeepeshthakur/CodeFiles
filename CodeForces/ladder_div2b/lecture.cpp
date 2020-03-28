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
	std::cin >> n >> m;
	std::vector<string> lec(n);
	std::unordered_map<std::string,std::string> ht;
	for(int i=0;i<m;i++){
		std::string a,b;
		std::cin >> a >> b;
		if(a.size() > b.size()){
			ht.insert(std::make_pair(a,b));
		}
		else{
			ht.insert(std::make_pair(a,a));
		}
	}

	std::vector<std::string> ans(n);
	for(int i=0;i<n;i++){
		std::cin >> lec[i];
		ans[i] = ht[lec[i]];
	}

	for(int i=0;i<n;i++){
		std::cout << ans[i] << (i<n-1 ? " ":"\n");
	}
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
