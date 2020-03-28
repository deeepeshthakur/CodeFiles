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
void print_vec(vector<int>& a,int n=-1){
	n = (n==-1 ? a.size():n);
	for(int i=0;i<n;i++)
		cout << a[i] << (i<n-1 ? " ":"\n");
}

void print_vec(vector<long long>& a,int n=-1){
	n=(n==-1 ? a.size():n);
	for(int i=0;i<n;i++)
		cout << a[i] << (i<n-1 ? " ":"\n");
}

void dfs(int ind, vector<vector<int>>& gr, vector<bool>& vis, vector<int>& sc, int& a, int& b){
	if(vis[ind]){
		vis[ind]=false;
		int x=0,y=0;
		for(int i=0;i<gr[ind].size();i++){
			if(vis[gr[ind][i]]){
				dfs(gr[ind][i],gr,vis,sc,a,b);
				if(sc[gr[ind][i]]>=x){
					swap(x,y);
					x=sc[gr[ind][i]];
				}
				else{
					if(sc[gr[ind][i]]>y){
						y=sc[gr[ind][i]];
					}
				}
			}
		}
		sc[ind]=x;
		// cout<<ind+1<<" "<<x+y+1<<"\n";
		if(x+y>b){
			b=x+y;
			a=ind;
		}
	}
}

void dfs2(int ind, vector<vector<int>>& gr, vector<bool>& vis, vector<int>& sc,int dist){
	if(vis[ind]){
		vis[ind]=false;
		sc[ind]=dist;
		for(int i=0;i<gr[ind].size();i++){
			dfs2(gr[ind][i],gr,vis,sc,sc[ind]+1);
		}
	}
}

void solve(){
	int n;
	cin>>n;
	vector<vector<int>> gr(n);
	for(int i=0;i<n-1;i++){
		int x,y;
		cin>>x>>y;
		gr[x-1].pb(y-1);
		gr[y-1].pb(x-1);
	}
	int curr_max=0,mx=0;
	vector<int> sc(n,0);
	vector<bool> vis(n,true);
	dfs(0,gr,vis,sc,curr_max,mx);
	vector<int> ln(n,0);
	vector<bool> vis1(n,true);
	dfs2(curr_max,gr,vis1,ln,0);

	int a=0,b=0,c=0;
	for(int i=0;i<n;i++){
		if(ln[i]>=ln[a]){
			a=i;
		}
	}

	vector<int> ln2(n,0);
	vector<bool> vis2(n,true);
	dfs2(a,gr,vis2,ln2,0);
	for(int i=0;i<n;i++){
		if(ln2[i]>=ln2[b]){
			b=i;
		}
	}
	// print_vec(ln);
	// print_vec(ln2);

	for(int i=0;i<n;i++){
		if(i!=a&&i!=b){
			c=i;
			break;
		}
	}
	// cout<<curr_max+1<<" "<<mx<<"\n";
	cout<<ln2[b]<<"\n"<<a+1<<" "<<b+1<<" "<<c+1<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}