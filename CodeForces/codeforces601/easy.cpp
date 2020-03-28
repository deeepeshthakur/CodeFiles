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
// #define cin std::cin
// #define cout std::cout
// #define vector std::vector
// #define pair std::pair

using namespace std;
const double pi=acos(-1.0);
const double pii=2*pi;
const double eps=1e-6;
const long long MOD=1e9+7;

// void print_vec(std::vector<int>& a){
// 	for(int i=0;i<a.size();i++)
// 		std::cout << a[i] << (i<n-1 ? " ":"\n");
// }

// void print_vec(std::vector<long long>& a){
// 	for(int i=0;i<a.size();i++)
// 		std::cout << a[i] << (i<n-1 ? " ":"\n");
// }

// void solve_kick_start(int test_case){

// }

int get_min(std::vector<int>& a){
	if(a.size()==2){
		return std::abs(a[1] - a[0]);
	}

	int mid = (a.size()-1)/2;
	int ans = 0;
	for(int i=0;i<a.size();i++){
		ans += abs(a[mid]-a[i]);
	}
	return ans;
}

void solve(){
	int n;
	std::cin >> n;
	std::vector<int> a(n,0);
	int ctr=0;
	for(int i=0;i<n;i++){
		std::cin >> a[i];
		ctr+=a[i];
	}
	int ans = -1;
	for(int f = 2;f<=ctr;f++){
		if(ctr%f==0){
			int tmp = 0 ;
			int curr_i = 0;
			for(int i=0;i<n;i++){
				if(a[i] == 1){
					std::vector<int> ind{i};
					int j = i+1;
					while(ind.size()<f){
						if(a[j]==1){
							ind.pb(j);
						}
						j++;
					}
					tmp += get_min(ind);
					i = j;
				}
			}
			ans = tmp;
			break;
		}
	}
	std::cout << ans << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	// // CodeChef Template
	// int t;       
	// std::cin >> t;
	// while(t--){
	// 	solve();
	// }

	// Single test case input
	solve();

	// // Kick Start Template	
	// int test_cases;
	// std::cin >> test_cases;
	// for(int i=1;i<=test_cases;i++){
	// 	solve_kick_start(i);
	// }


	return 0;
}