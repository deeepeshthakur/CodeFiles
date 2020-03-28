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

void dfs(int ind, vector<vector<pair<int,int>>>& tr, vector<bool>& vis, vector<int>& edges){
	if(vis[ind]){
		vis[ind]=false;

		priority_queue<int,vector<int>,greater<int>> pq;
		for(int i=0;i<tr[ind].size();i++){
			if(edges[tr[ind][i].S]!=-1){
				pq.push(edges[tr[ind][i].S]);
			}
		}

		int color = 1;
		for(int i=0;i<tr[ind].size();i++){
			if(edges[tr[ind][i].S]==-1){
				while(!pq.empty() && pq.top() == color){
					color++;
					pq.pop();
				}
				edges[tr[ind][i].S]=color;
				color++;
			}
		}

		for(int i=0;i<tr[ind].size();i++){
			dfs(tr[ind][i].F,tr,vis,edges);
		}
	}
}

void solve(){
	int n;
	cin >> n;
	vector<vector<pair<int,int>>> tr(n);
	vector<int> edges(n-1,-1);

	for(int i=0;i<edges.size();i++){
		int a,b;
		cin >>a>>b;
		a--;
		b--;
		tr[a].pb({b,i});
		tr[b].pb({a,i});
	}

	vector<bool> vis(n,true);
	dfs(0,tr,vis,edges);
	int mx_col = 0;
	for(int i=0;i<edges.size();i++)
		mx_col = max(mx_col,edges[i]);

	cout << mx_col << "\n";
	for(int i=0;i<edges.size();i++){
		cout << edges[i] << "\n";
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