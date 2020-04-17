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

void bfs(int ind,queue<int>& qu, vector<bool>& vis, vector<vector<int>>& tr, vector<int>& dist){
    if(vis[ind]){
        vis[ind]=false;
        for(int i=0;i<tr[ind].size();i++){
            if(vis[tr[ind][i]]){
                dist[tr[ind][i]]=dist[ind]+1;
                qu.push(tr[ind][i]);
            }
        }
    }
}

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> tr(n);
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        tr[x-1].pb(y-1);
        tr[y-1].pb(x-1);
    }
    vector<int> bfs_tr(n,0);
    for(int i=0;i<n;i++){
        cin>>bfs_tr[i];
    }
    vector<bool> vis(n,true);
    vector<int> dist(n,0);
    queue<int> qu;
    qu.push(0);
    while(!qu.empty()){
        bfs(qu.front(),qu,vis,tr,dist);
        qu.pop();
    }

    int mx=0;
    bool flag=true;
    for(int i=0;i<n&&flag;i++){
        if(dist[bfs_tr[i]-1]>=mx){
            mx=max(mx,dist[bfs_tr[i]-1]);
        }
        else{
            flag=false;
        }
    }
    if(flag){
        vector<int> ordering(n,0);
        for(int i=0;i<bfs_tr.size()&&flag;i++){
            if(i>0 && ordering[bfs_tr[i]-1]<ordering[bfs_tr[i-1]-1]){
                flag=false;
            }
            for(int j=0;j<tr[bfs_tr[i]-1].size()&&flag;j++){
                if(dist[tr[bfs_tr[i]-1][j]]>dist[bfs_tr[i]-1]){
                    ordering[tr[bfs_tr[i]-1][j]]=i;
                }
            }
        }
    }
    cout<<(flag?"Yes\n":"No\n");
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}