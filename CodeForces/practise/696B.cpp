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

void dfs(int ind,vector<bool>& vis, vector<vector<int>>& tr, vector<int>& sc){
    if(vis[ind]){
        vis[ind]=false;
        for(int i=0;i<tr[ind].size();i++)
            if(vis[tr[ind][i]]){
                dfs(tr[ind][i],vis,tr,sc);
                sc[ind]+=sc[tr[ind][i]];
            }
        sc[ind]++;
    }
}

void dfs1(int ind,vector<bool>& vis, vector<vector<int>>& tr, double pr, vector<double>& prob, vector<int>& sc){
    if(vis[ind]){
        vis[ind]=false;
        prob[ind]=pr+1.0;
        for(int i=0;i<tr[ind].size();i++)
            if(vis[tr[ind][i]]){
                dfs1(tr[ind][i],vis,tr,prob[ind]+0.5*(sc[ind]-1-sc[tr[ind][i]]),prob,sc);
            }
    }
}

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> tr(n);
    for(int i=0;i<n-1;i++){
        int x=i+2,y;
        cin>>y;
        tr[x-1].pb(y-1);
        tr[y-1].pb(x-1);
    }

    vector<bool> vis(n,true),vis1(n,true);
    vector<int> sc(n,0);
    vector<double> prob(n,0.0);
    dfs(0,vis,tr,sc);
    dfs1(0,vis1,tr,0.0,prob,sc);
    for(int i=0;i<n;i++)
        cout<<fixed<<setprecision(8)<<prob[i]<<(i+1<n?" ":"\n");
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}