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
	int m, n;
	std::cin >> m;
	std::vector<int> dis(m,0);
	for(int i =0;i < m;i++){
		std::cin >> dis[i];
	}

	std::sort(full(dis));

	std::cin >> n;
	std::vector<int> items(n,0);
	for(int i=0;i<n;i++){
		std::cin >> items[i];
	}
	std::sort(full(items));

	long long ans = 0;
	int discount=dis[0];
	for(int i=n-1;i>-1;i--){
		// if(i+discount+2<= n){
		// 	int j=i;
		// 	while(j<i+discount){
		// 		ans += items[j];
		// 		j++;
		// 	}
		// 	i = j+2;
		// }
		// else{
		// 	if(i+discount+1 <= n){
		// 		int j = i;
		// 		while(j < i+discount){
		// 			ans += items[j];
		// 			j++;
		// 		}
		// 		i = j+1;
		// 	}
		// 	else{
		// 		int j = i;
		// 		while(j < i+discount){
		// 			ans += items[j];
		// 			j++;
		// 		}
		// 	}
		// }

		int j = i;
		while(j > std::max(-1,i-discount)){
			ans += items[j];
			j--;
		}

		if(j > -1){
			j--;
		}

		if(j > -1){
			j--;
		}

		i = j+1;
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