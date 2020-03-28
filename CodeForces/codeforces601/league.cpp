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

void solve(){
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> q(n-2,std::vector<int>(3,0));

	for(int i=0;i<q.size();i++){
		std::cin >> q[i][0] >> q[i][1] >> q[i][2];
		q[i][0]--;
		q[i][1]--;
		q[i][2]--;
	}

	std::vector<std::vector<int>> arr(n);
	for(int i=0;i<q.size();i++){
		for(int j=0;j<3;j++){
			arr[q[i][j]].pb(i);
		}
	}

	int o1 = -1;
	for(int i=0;i<n;i++){
		if(arr[i].size() == 1){
			o1 = i;
			break;
		}
	}


	int cur_2;
	if(arr[q[arr[o1][0]][0]].size() == 2)
		cur_2 = q[arr[o1][0]][0];
	else if(arr[q[arr[o1][0]][1]].size() == 2)
		cur_2 = q[arr[o1][0]][1];
	else if(arr[q[arr[o1][0]][2]].size() == 2)
		cur_2 = q[arr[o1][0]][2];

	std::vector<int> ans{o1,cur_2};
	std::set<int> ans_set;
	ans_set.insert(o1);
	ans_set.insert(cur_2);

	while(ans.size() < n){
		int x = ans[ans.size()-2], y = ans[ans.size()-1];
		for(int i=0;i<arr[x].size();i++){
			for(int j=0;j<arr[y].size();j++){
				if(arr[x][i]==arr[y][j]){
					int mtp = arr[x][i];
					for(int k=0;k<3;k++){
						ans_set.insert(q[mtp][k]);
						if(ans_set.size() > ans.size()){
							ans.pb(q[mtp][k]);
						}
					}
				}
			}
		}
	}

	for(int i=0;i<n;i++){
		std::cout << ans[i]+1 << (i<n-1 ? " ":"\n");
	}
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

	// // Single test case input
	solve();

	// // Kick Start Template	
	// int test_cases;
	// std::cin >> test_cases;
	// for(int i=1;i<=test_cases;i++){
	// 	solve_kick_start(i);
	// }


	return 0;
}