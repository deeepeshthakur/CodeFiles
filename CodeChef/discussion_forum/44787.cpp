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
	int work, users;
	std::cin >> work >> users;
	std::vector<int> a(users,0),time_taken(users,0);

	for(int i=0;i<users;i++)
		std::cin >> a[i];
	int ans = 0;
	for(int i=0;i<work;i++){
		int curr_min = int(1e9), ind = 0;
		for(int j=0;j<users;j++){
			if(time_taken[j]+a[j] < curr_min){
				curr_min = time_taken[j]+a[i];
				ind = j;
			}
		}
		time_taken[ind]=curr_min;
		ans = std::max(ans,time_taken[ind]);
	}
	std::cout << ans << "\n";
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