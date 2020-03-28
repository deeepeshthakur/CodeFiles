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

void dfs(int ind, int gnd, vector<vector<int>>& gr, vector<int>& gender, vector<bool>& vis, bool &flag){
	if(vis[ind]){
		vis[ind]=false;
		gender[ind]=gnd;

		for(int i=0;i<gr[ind].size();i++){
			if(gender[gr[ind][i]] == gnd){
				flag = false;
			}
		}

		for(int i=0;i<gr[ind].size();i++){
			dfs(gr[ind][i],(gnd+1)%2,gr,gender,vis,flag);
		}
	}
}

void solve(int test_case){
	int n,m,a,b;
	cin>>n>>m;
	vector<vector<int>> gr(n);
	for(int i=0;i<m;i++){
		cin>>a>>b;
		gr[a-1].pb(b-1);
		gr[b-1].pb(a-1);
	}

	bool flag = true;

	vector<int> gender(n,-1);
	vector<bool> vis(n,true);

	for(int i=0;i<n;i++)
		dfs(i,0,gr,gender,vis,flag);

	if(flag)
		cout << "No suspicious lizards found!\n";
	else
		cout << "Suspicious lizards found!\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int test_cases;
	cin >> test_cases;
	for(int i=1;i<=test_cases;i++){
		solve(i);
	}

	return 0;
}