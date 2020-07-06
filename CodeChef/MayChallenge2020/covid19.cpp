#include<bits/stdc++.h>
using namespace std;

int dfs(int index,vector<bool>& vis, vector<vector<bool>>& adj){
    if(vis[index]){
        vis[index]=false;
        int ret=1;
        for(int i=0;i<adj.size();i++){
            if(adj[index][i]) ret+=dfs(i,vis,adj);
        }
        return ret;
    }
    return 0;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;cin>>n;
        vector<int> x(n,0);
        for(int i=0;i<n;i++) cin>>x[i];
        vector<vector<bool>> adj(n,vector<bool>(n,false));
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) adj[i][j]=(abs(x[i]-x[j])<=2);
        vector<bool> vis(n,true);
        set<int> sc;
        for(int i=0;i<n;i++) if(vis[i]) sc.insert(dfs(i,vis,adj));
        int mn=100,mx=0;
        for(auto itr=sc.begin();itr!=sc.end();itr++){
            mn=min(mn,*itr);
            mx=max(mx,*itr);
        }
        cout<<mn<<" "<<mx<<"\n";
    }
    return 0;
}