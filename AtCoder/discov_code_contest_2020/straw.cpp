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

// long long pow_mod(long long a, long long b){
// 	if(a == 0)
// 		return 0ll;
// 	if(b == 0)
// 		return 1ll;
// 	if(b == 1)
// 		return a%MOD;
// 	long long x = pow_mod(a,b/2);
// 	return ((b%2 == 1) ? (((x*x)%MOD)*a)%MOD : (x*x)%MOD);
// }

// long long pow_int(long long a, long long b){
// 	if(a==0)
// 		return a;
// 	if(b==0)
// 		return 1;
// 	if(b==1)
// 		return a;
// 	long long x = pow_int(a,b/2);
// 	return ((b%2 == 1) ? x*x*a : x*x);
// }

// int pow_int(int a, int b){
// 	if(a==0)
// 		return a;
// 	if(b==0)
// 		return 1;
// 	if(b==1)
// 		return a;
// 	int x = pow_int(a,b/2);
// 	return ((b%2 == 1) ? x*x*a : x*x);
// }


// void print_vec(vector<int>& a){
// 	for(int i=0;i<a.size();i++)
// 		cout << a[i] << (i<n-1 ? " ":"\n");
// }

// void print_vec(vector<long long>& a){
// 	for(int i=0;i<a.size();i++)
// 		cout << a[i] << (i<n-1 ? " ":"\n");
// }

// void solve_kick_start(int test_case){

// }

void solve(){
	int h,w,k;
	cin >> h >> w >> k;
	vector<string> dp(h);
	vector<vector<int>> ans(h,vector<int>(w,0));
	for(int i=0;i<h;i++){
		cin >> dp[i];
	}

	int curr_k = 1;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(dp[i][j]=='#'){
				ans[i][j]=curr_k;
				curr_k++;
			}
		}
	}

	for(int i=0;i<h;i++){
		for(int j=1;j<w;j++){
			if(ans[i][j]==0 && ans[i][j-1]!=0){
				ans[i][j]=ans[i][j-1];
			}
		}
		for(int j=w-1;j>0;j--){
			if(ans[i][j-1]==0 && ans[i][j]!=0){
				ans[i][j-1]=ans[i][j];
			}
		}
	}

	for(int j=0;j<w;j++){
		for(int i=1;i<h;i++){
			if(ans[i][j]==0 && ans[i-1][j]!=0){
				ans[i][j]=ans[i-1][j];
			}
		}

		for(int i=h-1;i>0;i--){
			if(ans[i][j]!=0 && ans[i-1][j] == 0){
				ans[i-1][j] = ans[i][j];
			}
		}
	}

	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cout << ans[i][j] << (j < w-1 ? " ":"\n");
		}
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