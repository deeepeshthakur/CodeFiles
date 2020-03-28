#include<bits/stdc++.h>
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

int rec_f(int ind, vector<vector<int>>& tr, vector<int>& arr){
	int curr_node = arr[ind];

	int i=ind+1;
	while(arr[i]!=curr_node){
		tr[curr_node].pb(arr[i]);
		i=rec_f(i,tr,arr);
	}
	return i+1;
}


int dfs_fun(int ind, vector<int>& ans, vector<vector<int>>& tr, vector<bool>& vis){
	int s = 0;
	if(vis[ind]){
		vis[ind]=false;
		s=1;
		for(int i=0;i<tr[ind].size();i++){
			if(vis[tr[ind][i]]){
				s += dfs_fun(tr[ind][i],ans,tr,vis);
			}
		}
		ans[ind]=s;
	}
	return s;
}

void solve(){
	int n;
	cin>>n;
	vector<int> arr(n,0);

	for(int i=0;i<n;i++){
		cin>>arr[i];
		arr[i]--;
	}

	vector<vector<int>> tr(n/2);

	int tmp = rec_f(0,tr,arr);
	vector<int> ans(tr.size(),0);
	vector<bool> vis(ans.size(),true);

	ans[0] = dfs_fun(0,ans,tr,vis);
	for(int i=0;i<tr.size();i++){
		cout << ans[i] << (i < tr.size() - 1  ? " " : "\n");  
	}

}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	// // CodeChef Template
	// int t;       
	// cin >> t;
	// while(t--){
	// 	solve();
	// }

	// Single test case input
	solve();

	// // Kick Start Template	
	// int test_cases;
	// cin >> test_cases;
	// for(int i=1;i<=test_cases;i++){
	// 	solve_kick_start(i);
	// }

	return 0;
}