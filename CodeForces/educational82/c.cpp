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

void dfs(int parent, int ind, vector<bool>& vis, vector<vector<int>>& gr, vector<vector<int>>& connections){
	if(vis[ind]){
		vis[ind]=false;
		connections[parent].pb(ind);
		for(int i=0;i<26;i++){
			if(ind!=i && gr[ind][i]==1){
				dfs(parent,i,vis,gr,connections);
			}
		}
	}
}

void solve(){
	int n;
	string s;
	cin>>s;
	n=s.size();
	if(s.size()==1){
		cout<<"YES\nabcdefghijklmnopqrstuvwxyz\n";
		return;
	}
	vector<int> a(n,0);
	for(int i=0;i<n;i++)
		a[i]=int(s[i]-'a');
	vector<vector<int>> gr(26,vector<int>(26,0));
	for(int i=0;i<n;i++){
		if(i>0){
			gr[a[i]][a[i-1]]=1;
		}

		if(i+1<n){
			gr[a[i]][a[i+1]]=1;
		}
	}

	int mx=0;
	for(int i=0;i<26;i++){
		int tmp=0;
		for(int j=0;j<26;j++)
			tmp+=gr[i][j];
		if(mx<tmp)
			mx=tmp;
	}

	if(mx>2){
		cout<<"NO\n";
		return;
	}
	vector<bool> vis(26,true);
	vector<vector<int>> connections(26);
	for(int i=0;i<26;i++){
		int txp=0;
		for(int j=0;j<26;j++){
			if(j!=i&&gr[i][j]==1)
				txp++;
		}
		if(txp==1)
			dfs(i,i,vis,gr,connections);
	}

	if(true){
		int cnt=0;
		for(int i=0;i<26;i++){
			if(vis[i])
				cnt++;
		}
		if(cnt>=26){
			cout<<"NO\n";
			return;
		}
	}

	for(int i=0;i<26;i++){
		dfs(i,i,vis,gr,connections);
	}

	vector<char> ans;
	for(int i=0;i<26;i++){
		for(int j=0;j<connections[i].size();j++){
			ans.pb(char(int('a'+connections[i][j])));
		}
	}

	cout<<"YES\n";
	for(int i=0;i<ans.size();i++){
		cout<<ans[i];
	}
	cout<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int t;       
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}