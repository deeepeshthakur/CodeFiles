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

// void print_vec(std::vector<int>& a){
// 	for(int i = 0; i < a.size(); i++)
// 		std::cout << a[i] << " ";
// 	std::cout << "\n";
// }

bool check_flag(std::vector<int>& a){
	int ans = a[0] + a[1] + a[2];
	return (ans == (a[3] + a[4] + a[5])) && (ans == (a[6] + a[7] + a[8])) && (ans == (a[0] + a[3] + a[6])) && (ans == (a[1] + a[4] + a[7])) && (ans == (a[2] + a[5] + a[8])) && (ans == (a[0] + a[4] + a[8])) && (ans == (a[2] + a[4] + a[6]));
}

void rec_fun(std::vector<std::vector<int>>& sq, int index, std::vector<int> curr){
	if(index >= 8){
		if(check_flag(curr))
			sq.push_back(curr);
	}
	else{
		for(int i = index; i < 9; i++){
			std::vector<int> tmp(curr);
			{
				int t = tmp[index];
				tmp[index] = tmp[i];
				tmp[i] = t;
			}

			rec_fun(sq,index+1,tmp);
		}
	}	
}

void get_all_sq(std::vector<std::vector<int>>& sq){
	std::vector<int> tmp{1,2,3,4,5,6,7,8,9};
	rec_fun(sq,0,tmp);
}

int get_cost(std::vector<int>& a, std::vector<int>& b){
	int ans = 0;
	for(int i = 0; i < 9; i++){
		ans += std::abs(a[i]-b[i]);
	}
	return ans;
}

void solve(){
	std::vector<int> arr(9,0);
	for(int i = 0; i < 9; i++){
		std::cin >> arr[i];
	}

	int cost = 1000;
	std::vector<std::vector<int>> all_sq;
	get_all_sq(all_sq);

	for(int i = 0; i < all_sq.size(); i++){
		cost = std::min(cost,get_cost(arr,all_sq[i]));
	}
	// std::cout << all_sq.size() << "\n";
	std::cout << cost << "\n";
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