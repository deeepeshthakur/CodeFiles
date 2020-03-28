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

long long gcd_f(long long a, long long b){
	if(a > b)
		return gcd_f(b,a);

	return (a == 0 ? b : gcd_f(a,b%a));
}

void solve(){
	int n;
	std::cin >> n;
	std::vector<long long> b(n,0ll);
	long long gcdd = 0ll;
	for(int i = 0; i < n; i++){
		std::cin >> b[i];
		gcdd = gcd_f(gcdd,b[i]);
	}

	for(int i = 0; i < n; i++){
		b[i] /= gcdd;
	}

	std::vector<long long> odd, ev1, ev2;
	

	std::vector<long long> ans;
	for(int i = 0; i < n; i++){
		if((b[i]/gcdd)%2 == 0){
			ans.push_back(b[i]);
		}
	}

	std::cout << ans.size() << "\n";
	for(int i = 0; i < ans.size(); i++){
		std::cout << ans[i] << (i + 1 < ans.size() ? " " : "\n");
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