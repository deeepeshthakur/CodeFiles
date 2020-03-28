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
	std::vector<int> tran(n,0), curr(n,0), nxt(n,0), ans(n,-1);
	for(int i=0;i<n;i++){
		int a;
		std::cin >>a;
		tran[i] = a-1;

		curr[i] = i;
	}
	
	int tot = n;
	for(int ctr=1;tot>0;ctr++){
		// std::cout << ctr << " " << tot << "     ----     ";
		// print_vec(curr);
		for(int i=0;i<n;i++){
			nxt[i] = tran[curr[i]];
		}

		for(int i=0;i<n;i++){
			curr[i] = nxt[i];
			if(curr[i] == i && ans[i] == -1){
				ans[i] = ctr;
				tot--;
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