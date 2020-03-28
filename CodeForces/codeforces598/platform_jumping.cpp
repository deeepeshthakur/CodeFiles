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
	int n,m,d;
	std::cin >> n >> m >> d;
	std::vector<int> arr(m,0);
	for(int i=0;i<m;i++)
		std::cin >> arr[i];

	int x = 0;
	for(int i=0;i<m;i++){
		x += arr[i]+d-1;
	}

	x+=d;
	if(x >= n+1){
		std::cout << "YES\n";
		// int summ = 0;
		// for(int i=0;i<m;i++)
		// 	summ+=arr[i];
		// int ctr = 0,curr_d = std::min(d-1,n - ctr - summ);
		// for(int i=0;i<m;i++){
		// 	curr_d = std::min(d-1,n-ctr-summ);
		// 	for(int j=0;j<curr_d;j++){
		// 		std::cout << "0 ";
		// 		ctr++;
		// 	}

		// 	for(int j=0;j<arr[i];j++){
		// 		std::cout << i+1 << " ";
		// 	}
		// }

		// curr_d = std::min(d-1,n-ctr-summ);
		// for(int j=0;j<curr_d;j++){
		// 	std::cout << "0 ";
		// }
		// std::cout << "\n";

	}
	else{
		std::cout << "NO\n";
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