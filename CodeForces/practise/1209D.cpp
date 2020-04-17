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

void dfs(int ind,vector<bool>& vis, vector<vector<int>>& gr){
    if(vis[ind]){
        vis[ind]=false;
        for(int i=0;i<gr[ind].size();i++){
            dfs(gr[ind][i],vis,gr);
        }
    }
}

void solve(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>> gr(n);
    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        gr[x-1].pb(y-1);gr[y-1].pb(x-1);
    }

    vector<bool> vis(n,true);
    int ctr=0;
    for(int i=0;i<n;i++){
        if(vis[i]){
            ctr++;
            dfs(i,vis,gr);
        }
    }
    cout<<k-n+ctr<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}