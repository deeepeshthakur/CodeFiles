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

int max_layer = 0;

void divide_fun(int l, int r, std::vector<std::vector<int>>& dp, int layer){
	if(r > l){
		int mid = (l+r)/2;
		for(int i = l; i <= mid; i++)
			dp[layer][i] = 0;

		divide_fun(l,mid,dp,layer+1);
		divide_fun(mid+1,r,dp,layer+1);
		max_layer = std::max(max_layer,layer);
	}
}

bool compare_f(std::pair<int,int>& a, std::pair<int,int>& b){
	return ((a.S < b.S) || (a.S == b.S && a.F < b.F));
}

void solve(){
	int n,m;
	std::cin >> n >> m;
	std:vector<std::vector<int>> gr(n);
	std::vector<bool> visited(n,true);
	std::vector<std::pair<int,int>> edges;
	
	for(int i = 0; i < m; i++){
		int a,b;
		std::cin >> a >> b;
		a--;
		b--;
		edges.push_back({a,b});
		edges.push_back({b,a});
	}

	std::sort(full(edges),compare_f);

	for(int i = 0; i < edges.size(); i++){
		gr[edges[i].F].push_back(edges[i].S);
	}

	std::vector<std::vector<int>> strong_groups;
	std::vector<int> arr(n,0), group_numbers(n,0);
	
	for(int i = 0; i < n; i++)
		arr[i] = i;

	bool flag1 = true, flag2 = true;
	
	while(flag2){
		int remaining_ele = arr.size(), edge_arr0 = gr[arr[0]].size();
		std::vector<int> temp_arr, temp_arr2;

		for(int i = 0; i < edge_arr0; i++){
			if(visited[gr[arr[0]][i]]){
				temp_arr.push_back(gr[arr[0]][i]);
			}
		}

		int j = 0;
		for(int i = 0; i < remaining_ele; i++){
			if(j < temp_arr.size() && temp_arr[j] == arr[i])
				j++;
			else
				temp_arr2.push_back(arr[i]);
		}

		std::set<int> dis_nodes;
		for(int i = 0; i < temp_arr.size(); i++)
			dis_nodes.insert(temp_arr[i]);

		for(int i = 0; i < temp_arr2.size(); i++){
			int len = gr[temp_arr2[i]].size();
			j = 0;
			for(int k = 0; k < len; k++){
				if(visited[gr[temp_arr2[i]][k]]){
					j++;
					dis_nodes.insert(gr[temp_arr2[i]][k]);
				}
			}
			flag1 = (flag1 && (temp_arr.size() == j));
		}

		flag1 = (flag1 && (dis_nodes.size() == temp_arr.size()));

		for(int i = 0; i < temp_arr2.size(); i++)
			visited[temp_arr2[i]] = false;

		if(flag1){
			strong_groups.push_back(temp_arr2);
			arr.resize(temp_arr.size());
			for(int i = 0; i < arr.size(); i++)
				arr[i] = temp_arr[i];
		}

		flag2 = (arr.size() > 0 && flag1);
	}

	if(flag1){
		int tot_groups = strong_groups.size(), group_i_len;
		for(int i = 0; i < tot_groups; i++){
			group_i_len = strong_groups[i].size();
			for(int j = 0; j < group_i_len; j++){
				group_numbers[strong_groups[i][j]] = i;
			}
		}

		std::vector<std::vector<int>> dp_table(20 + int(log2(tot_groups)),std::vector<int>(tot_groups,1));
		divide_fun(0,tot_groups-1,dp_table,0);

		if(tot_groups > 1){
			std::cout << max_layer + 1 << "\n";
			for(int i = 0; i <= max_layer; i++){
				for(int j = 0; j < n; j++){
					std::cout << dp_table[i][group_numbers[j]];
				}
				std::cout << "\n";
			}
		}
		else
			std::cout << "0\n";
	}
	else{
		std::cout << "-1\n";
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