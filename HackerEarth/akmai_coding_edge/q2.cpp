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

long double dfs(int ind, vector<vector<pair<int,int>>>& tr, vector<bool>& vis, vector<long double>& prob, vector<int>& d_p){
	if(vis[ind]){
		vis[ind]=false;
		long double profit = 0.0;

		for(int i=0;i<tr[ind].size();i++){
			if(vis[tr[ind][i].F]){
				profit += prob[tr[ind][i].S]*(d_p[tr[ind][i].S]+dfs(tr[ind][i].F,tr,vis,prob,d_p));
			}
		}
		return profit;
	}
	return (long double)(0.0);
}

void solve(){
	int n;
	cin>>n;
	vector<int> u(n-1,0),v(n-1,0),d_p(n-1,0);
	vector<long double> prob(n-1,1.0);
	vector<vector<pair<int,int>>> tr(n);
	for(int i=0;i<n-1;i++){
		cin>>u[i]>>v[i]>>d_p[i]>>prob[i];
		u[i]--;
		v[i]--;
		tr[u[i]].pb({v[i],i});
		tr[v[i]].pb({u[i],i});
	}

	vector<bool> vis(n,true);
	long double prof = dfs(0,tr,vis,prob,d_p);
	cout << fixed << setprecision(6) << prof << "\n";
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