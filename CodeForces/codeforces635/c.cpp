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
const long long MOD=1e7;

void dfs(int ind, int high,vector<bool>& vis, vector<int>& ht, vector<int>& ht1, vector<vector<int>>& tr){
    if(vis[ind]){
        vis[ind]=false;
        ht1[ind]=high+1;
        ht[ind]=0;
        for(int i=0;i<tr[ind].size();i++){
            if(vis[tr[ind][i]]){
                dfs(tr[ind][i],ht1[ind],vis,ht,ht1,tr);
                ht[ind]+=ht[tr[ind][i]];
            }
        }
        ht[ind]+=1;
    }
}

void dfs1(int ind, int score, vector<bool>& vis, vector<int>& sc, vector<int>& iden, vector<vector<int>>& tr){
    if(vis[ind]){
        vis[ind]=false;
        sc[ind]=score+iden[ind];
        for(int i=0;i<tr[ind].size();i++){
            dfs1(tr[ind][i],sc[ind],vis,sc,iden,tr);
        }
    }
}

void solve(){
    int n,k;cin>>n>>k;
    vector<vector<int>> tr(n);
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        tr[x-1].pb(y-1);
        tr[y-1].pb(x-1);
    }

    vector<bool> vis(n,true),vis1(n,true);
    vector<int> ht1(n,0),ht2(n,0);
    vector<pair<int,int>> ht(n,{0ll,0});
    dfs(0,0,vis,ht1,ht2,tr);
    
    for(int i=0;i<n;i++){
        ht[i].second=i;
        ht[i].first=(ht1[i]-ht2[i]);//+1ll*(n+10-ht2[i]);
    }
    vector<int> iden(n,1);
    sort(full(ht));
    for(int i=0;i<k;i++){
        iden[ht[i].second]=0;
    }
    vector<int> sc(n,0);
    dfs1(0,0,vis1,sc,iden,tr);
    long long ans=0;
    for(int i=0;i<n;i++){
        if(iden[i]==0){
            ans+=sc[i];
        }
    }
    cout<<ans<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}