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

void bfs(int ind, int len, vector<bool>& vis, queue<int>& bfsq, vector<vector<int>>& gr, vector<int>& path){
	if(vis[ind]){
		vis[ind]=false;
		for(int i=0;i<gr[ind].size();i++){
			path[gr[ind][i]]=min(len+1,path[gr[ind][i]]);
			bfsq.push(gr[ind][i]);
		}
	}
}

void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> special(k,0);
	for(int i=0;i<k;i++){
		cin>>special[i];
		special[i]--;
	}	

	vector<vector<int>> gr(n);
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		x--;
		y--;
		gr[x].pb(y);
		gr[y].pb(x);
	}

	vector<bool> vis1(n,true),vis2(n,true);
	vector<int> pt1(n,int(1e6)),pt2(n,int(1e6));

	queue<int> bfsq1,bfsq2;
	bfsq1.push(0);
	bfsq2.push(n-1);
	pt1[0]=0;
	pt2[n-1]=0;
	while(!bfsq1.empty()){
		int ind=bfsq1.front();
		bfsq1.pop();
		bfs(ind,pt1[ind],vis1,bfsq1,gr,pt1);
	}

	while(!bfsq2.empty()){
		int ind=bfsq2.front();
		bfsq2.pop();
		bfs(ind,pt2[ind],vis1,bfsq1,gr,pt1);
	}

	int ans=pt1[n-1];

	vector<pair<int,int>> l1,l2;
	for(int i=0;i<k;i++){
		if(pt1[special[i]]<pt2[special[i]]){
			l1.pb({pt1[special[i]],special[i]});
		}

		if(pt1[special[i]]>pt2[special[i]]){
			l2.pb({pt2[special[i]],special[i]});
		}

		if(pt1[special[i]]==pt2[special[i]]){
			l1.pb({pt1[special[i]],special[i]});
			l2.pb({pt2[special[i]],special[i]});
		}
	}

	sort(full(l1));
	sort(full(l2));

	
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}