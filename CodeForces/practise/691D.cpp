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

void dfs(int ind, int cluster, vector<int>& clus, vector<bool>& vis, vector<vector<int>>& gr){
    if(vis[ind]){
        vis[ind]=false;
        clus[ind]=cluster;
        for(int i=0;i<gr[ind].size();i++) dfs(gr[ind][i],cluster,clus,vis,gr);
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> p(n,0),cluster(n,0);
    vector<vector<int>> gr(n);
    for(int i=0;i<n;i++) cin>>p[i];
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        gr[x-1].pb(y-1);
        gr[y-1].pb(x-1);
    }
    vector<bool> vis(n,true);
    int ctr=0;
    for(int i=0;i<n;i++){
        if(vis[i]){
            dfs(i,ctr,cluster,vis,gr);
            ctr++;
        }
    }
    vector<priority_queue<int>> pqs(ctr);
    for(int i=0;i<n;i++) pqs[cluster[i]].push(p[i]);

    vector<int> ans(n,0);
    for(int i=0;i<n;i++){
        cout<<pqs[cluster[i]].top()<<(i+1<n?" ":"\n");
        pqs[cluster[i]].pop();
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}