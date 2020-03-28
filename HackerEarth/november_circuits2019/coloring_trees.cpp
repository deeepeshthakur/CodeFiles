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

void start_dfs(int ind,vector<int>& score, vector<int>& ind_score, vector<bool>& vis, vector<vector<int>>& tr){
	if(vis[ind]){
		vis[ind] = false;
		for(int i=0;i<tr[ind].size();i++){
			if(vis[tr[ind][i]]){
				start_dfs(tr[ind][i],score,ind_score,vis,tr);
				score[ind] += score[tr[ind][i]];
			}
		}
		score[ind]+=ind_score[ind];
	}
}

void solve(){
	int n,k;
	cin >> n >> k;
	vector<vector<int>> tr(n);
	for(int i=0;i<n-1;i++){
		int a,b;
		cin >>a>>b;
		tr[a-1].pb(b-1);
		tr[b-1].pb(a-1);
	}

	vector<int> score(n,0), ind_score(n,0);
	vector<bool> vis(n,true);
	for(int i=0;i<k;i++){
		int a;
		cin >> a;
		ind_score[a-1]=1;
	}

	for(int i=0;i<n;i++){
		if(ind_score[i]!=0){
			start_dfs(i,score,ind_score,vis,tr);
			break;
		}
	}

	int ans=0;
	for(int i=0;i<n;i++)
		ans += (score[i] > 0 ? 1 : 0);
	cout << ans << "\n";
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