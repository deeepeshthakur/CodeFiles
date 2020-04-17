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

void dfs(int ind, int parent, vector<int>& par, vector<bool>& vis, vector<vector<int>>& tr){
    if(vis[ind]){
        vis[ind]=false;
        par[ind]=parent;
        for(int i=0;i<tr[ind].size();i++){
            dfs(tr[ind][i],ind,par,vis,tr);
        }
    }
}

void dfs1(int ind, vector<bool>& vis, vector<int>& is_req, vector<vector<int>>& tr){
    if(vis[ind]){
        vis[ind]=false;
        bool flag=(is_req[ind]==1)?true:false;
        for(int i=0;i<tr[ind].size();i++){
            if(vis[tr[ind][i]]){
                dfs1(tr[ind][i],vis,is_req,tr);
                is_req[ind]+=is_req[tr[ind][i]];
            }
        }
        if(!flag && is_req[ind]==1) is_req[ind]++;
    }
}

void solve(){
    int n;cin>>n;
    vector<vector<int>> tr(n);
    vector<vector<int>> cond(n-1,vector<int>(3,0));
    for(int i=0;i<n-1;i++){
        cin>>cond[i][0]>>cond[i][1]>>cond[i][2];
        cond[i][0]--;cond[i][1]--;
        tr[cond[i][0]].pb(cond[i][1]);
        tr[cond[i][1]].pb(cond[i][0]);        
    }
    vector<int> par(n,0), is_req(n,false); vector<bool> vis(n,true),vis1(n,true);
    dfs(0,-1,par,vis,tr);
    for(int i=0;i<n-1;i++){
        if(par[cond[i][0]]==cond[i][1] && cond[i][2]==2) is_req[cond[i][0]]=1;
        if(par[cond[i][1]]==cond[i][0] && cond[i][2]==2) is_req[cond[i][1]]=1;
    }
    dfs1(0,vis1,is_req,tr);
    vector<int> ans;
    for(int i=0;i<n;i++) if(is_req[i]==1) ans.pb(i+1);
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";cout<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}