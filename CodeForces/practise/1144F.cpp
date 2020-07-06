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

void dfs(int ind, int pr, vector<int>& sc, vector<bool>& vis, vector<vector<int>>& gr){
    if(vis[ind]){
        vis[ind]=false;
        sc[ind]=pr;
        for(int i=0;i<gr[ind].size();i++){
            dfs(gr[ind][i],(pr+1)%2,sc,vis,gr);
        }
    }
}

void solve(){
    int n,m;cin>>n>>m;
    vector<pair<int,int>> edges(m,{0,0});
    vector<vector<int>> gr(n);
    for(int i=0;i<m;i++){
        cin>>edges[i].first>>edges[i].second;
        edges[i].first--;edges[i].second--;
        gr[edges[i].first].pb(edges[i].second);
        gr[edges[i].second].pb(edges[i].first);
    }
    vector<bool> vis(n,true);
    vector<int> sc(n,-1),ed_sc(m,-1);

    dfs(0,0,sc,vis,gr);
    bool flag=true;
    for(int i=0;i<m && flag;i++){
        if(sc[edges[i].first]+sc[edges[i].second]==1){
            if(sc[edges[i].first]==1)
                ed_sc[i]=1;
            else
                ed_sc[i]=0;
        }
        else{
            flag=false;
        }
    }
    if(flag){
        cout<<"YES\n";
        for(int i=0;i<m;i++) cout<<ed_sc[i];
        cout<<"\n";
    }
    else{
        cout<<"NO\n";
    }

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}