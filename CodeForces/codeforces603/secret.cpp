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

void dfs(int ind,vector<vector<bool>>& gr, vector<bool>& vis){
	if(vis[ind]){
		vis[ind]=false;
		for(int i=0;i<26;i++){
			if(gr[ind][i]){
				dfs(i,gr,vis);
			}
		}
	}
}

void solve(){
	vector<bool> vis(26,false);
	vector<long long> mul(26,1ll);
	for(int i=1;i<26;i++){
		mul[i]=mul[i-1]*2ll;
	}
	int n;
	cin>>n;
	vector<long long> dp(n,0ll);
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		vector<int> ch(26,0);
		for(int j=0;j<s.size();j++){
			ch[int(s[j]-'a')]=1;
			vis[int(s[j]-'a')]=true;
		}
		for(int j=0;j<26;j++){
			dp[i]+=ch[j]*mul[j];
		}
	}
	
	sort(full(dp));
	bool flag=true;
	vector<vector<int>> tab(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<26;j++){
			if((mul[j]&dp[i])>0)
			 	tab[i].pb(j);
		}
	}

	vector<vector<bool>> dp_table(26,vector<bool>(26,false));
	for(int i=0;i<n;i++){
		for(int j=1;j<tab[i].size();j++){
			dp_table[tab[i][j-1]][tab[i][j]]=true;
			dp_table[tab[i][j]][tab[i][j-1]]=true;
		}
	}

	int ans=0;
	for(int i=0;i<26;i++){
		if(vis[i]){
			ans++;
			dfs(i,dp_table,vis);
		}
	}

	cout << ans << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	solve();
	
	return 0;
}