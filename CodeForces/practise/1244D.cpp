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

void dfs(int ind, int d, vector<bool>& vis, vector<int>& dist, vector<vector<int>>& tr){
    if(vis[ind]){
        vis[ind]=false;
        dist[ind]=d;
        for(int i=0;i<tr[ind].size();i++){
            dfs(tr[ind][i],d+1,vis,dist,tr);
        }
    }
}

void solve(){
    int n;cin>>n;
    vector<vector<long long>> cl(n,vector<long long>(3,0ll));
    for(int j=0;j<3;j++){
        for(int i=0;i<n;i++){
            cin>>cl[i][j];
        }
    }
    vector<int> dist(n,0);
    vector<bool> vis(n,true);
    vector<vector<int>> tr(n);
    for(int i=0;i<n-1;i++){
        int x,y;cin>>x>>y;
        x--;y--;
        tr[x].pb(y);
        tr[y].pb(x);
    }
    for(int i=0;i<n;i++){
        if(tr[i].size()==1){
            dfs(i,0,vis,dist,tr);
        }
    }

    vector<pair<int,int>> sn(n,{0,0});
    for(int i=0;i<n;i++){
        sn[i].first=dist[i];
        sn[i].second=i;
    }
    sort(full(sn));
    if(sn[n-1].first!=n-1){
        cout<<"-1\n";
        return;
    }

    vector<vector<long long>> dp(n,vector<long long>(6,0ll));
    dp[1]={cl[sn[0].second][0]+cl[sn[1].second][1],
           cl[sn[0].second][0]+cl[sn[1].second][2],
           cl[sn[0].second][1]+cl[sn[1].second][0],
           cl[sn[0].second][1]+cl[sn[1].second][2],
           cl[sn[0].second][2]+cl[sn[1].second][0],
           cl[sn[0].second][2]+cl[sn[1].second][1]
          };
    
    for(int i=2;i<n;i++){
        dp[i][0]=cl[sn[i].second][1]+dp[i-1][4];
        dp[i][1]=cl[sn[i].second][2]+dp[i-1][2];
        dp[i][2]=cl[sn[i].second][0]+dp[i-1][5];
        dp[i][3]=cl[sn[i].second][2]+dp[i-1][0];
        dp[i][4]=cl[sn[i].second][0]+dp[i-1][3];
        dp[i][5]=cl[sn[i].second][1]+dp[i-1][1];
    }
    long long ans=dp[n-1][0],b;
    for(int i=0;i<6;i++){
        if(ans>=dp[n-1][i]){
            ans=dp[n-1][i];
            b=i;
        }
    }
    cout<<ans<<"\n";
    vector<pair<int,int>> avec(n,{0,0});
    vector<pair<int,int>> xx{{0,1},{0,2},{1,0},{1,2},{2,0},{2,1}};
    for(int i=0;i<6;i++){
        if(b==i){
            avec[n-2]={sn[n-2].second,xx[i].first};
            avec[n-1]={sn[n-1].second,xx[i].second};
        }
    }
    for(int i=n-3;i>=0;i--){
        avec[i]={sn[i].second,3-avec[i+1].second-avec[i+2].second};
    }
    sort(full(avec));
    for(int i=0;i<n;i++){
        cout<<avec[i].second+1<<" ";
    }
    cout<<"\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}