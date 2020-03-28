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
	int k;
	std::cin >> k;
	std::vector<std::vector<long long>> box(k);

	std::vector<long long> sum_box(k,0ll);
	long long tot_sum=0,avg;
	for(int i=0;i<k;i++){
		std::cin >> n;
		box[i].resize(n);
		for(int j=0;j<n;j++){
			std::cin >> box[i][j];
			sum_box[i] += box[i][j];
		}
		tot_sum += sum_box[i];
	}

	if(tot_sum%k != 0){
		std::cout << "No\n";
		return;
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