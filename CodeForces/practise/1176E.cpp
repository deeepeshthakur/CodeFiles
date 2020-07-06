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

void dfs(int ind, int pr, vector<int>& sc, vector<bool>& vis, vector<vector<int>>& tr){
    if(vis[ind]){
        vis[ind]=false;
        sc[ind]=pr;
        for(int i=0;i<tr[ind].size();i++){
            dfs(tr[ind][i],(pr+1)%2,sc,vis,tr);
        }
    }
}

void solve(){
    int n,m;cin>>n>>m;
    vector<vector<int>> gr(n);
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        x--;y--;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    vector<bool> vis(n,true);
    vector<int> sc(n,-1);
    dfs(0,0,sc,vis,gr);
    int o=0,e=0;
    for(int i=0;i<n;i++){
        if(sc[i]==0) e++;
        else o++;
    }
    if(o<=e){
        cout<<o<<"\n";
        for(int i=0;i<n;i++) if(sc[i]==1) cout<<i+1<<" ";
        cout<<"\n";
    }
    else{
        cout<<e<<"\n";
        for(int i=0;i<n;i++) if(sc[i]==0) cout<<i+1<<" ";
        cout<<"\n";
    }
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