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

void print_vec(std::vector<unsigned long long>& a){
	for(int i = 0; i < a.size(); i++){
		std::cout << a[i] << (i < a.size() - 1 ? " ": "\n");
	}
}

void print_vec(std::vector<bool>& a){
	for(int i = 0; i < a.size(); i++){
		std::cout << a[i] << (i < a.size() - 1 ? " ": "\n");
	}
}

void print_vec(std::vector<long long>& a){
	for(int i = 0; i < a.size(); i++){
		std::cout << a[i] << (i < a.size() - 1 ? " ": "\n");
	}
}

void print_vec(std::vector<int>& a){
	for(int i = 0; i < a.size(); i++){
		std::cout << a[i] << (i < a.size() - 1 ? " ": "\n");
	}
}


void solve(){
	int n;
	std::cin >> n;
	std::vector<int> tran(n,0), ans(n,0);
	std::vector<bool> check_arr(n,true);

	for(int i = 0; i < n; i++){
		std::cin >> tran[i];
		tran[i]--;
	}

	for(int i = 0; i < n; i++){
		if(check_arr[i]){
			std::vector<int> cir;
			cir.pb(i);
			while(tran[cir[cir.size() - 1]] != i){
				cir.pb(tran[cir[cir.size() - 1]]);
			}

			// print_vec(cir);

			for(int j=0; j<cir.size(); j++){
				ans[cir[j]] = cir.size();
				check_arr[cir[j]] = false;
			}
		}
	}


	for(int i=0;i<n;i++){
		std::cout << ans[i] << (i < n - 1 ? " ":"\n");
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

	// 	solve();
	return 0;
}