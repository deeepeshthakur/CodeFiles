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

void dfs(int ind, int p, int h, vector<bool>& vis, vector<vector<int>>& tr, vector<int>& parent, vector<int>& level){
    if(vis[ind]){
        vis[ind]=false;
        parent[ind]=p;
        level[ind]=h;
        for(int i=0;i<tr[ind].size();i++)
            dfs(tr[ind][i],ind,h+1,vis,tr,parent,level);
    }
}

void fill_dp(int ind, vector<bool>& vis, vector<int>& parent, vector<vector<int>>& dp){
    if(parent[ind]>=0 && vis[parent[ind]]) fill_dp(parent[ind],vis,parent,dp);
    vis[ind]=false;
    dp[ind][0]=parent[ind];
    for(int i=1;i<dp[ind].size();i++)
        if(dp[ind][i-1]!=-1) dp[ind][i]=dp[dp[ind][i-1]][i-1];
        else break;
}

int f(int ind, int d, vector<vector<int>>& dp){
    if(d==0) return ind;
    if(d>0 && dp[ind][0]==-1) return -1;
    int curr=ind,curr_d=0;
    for(int i=0;i<dp[ind].size() && dp[ind][i]!=-1;i++){
        if((1<<i)<=d){
            curr=dp[ind][i];
            curr_d=(1<<i);
        }
    }
    return f(curr,d-curr_d,dp);
}

void solve(){
    int n,q;
    cin>>n>>q;
    vector<vector<int>> tr(n);
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        tr[x-1].pb(y-1);
        tr[y-1].pb(x-1);
    }
    int lim=1;
    while(n>=(1<<lim)) lim++;
    lim+=10;
    vector<vector<int>> dp(n,vector<int>(lim,-1));
    vector<int> parent(n,-1),level(n,0);
    vector<bool> vis(n,true),vis2(n,true);
    dfs(0,-1,1,vis,tr,parent,level);
    for(int i=0;i<n;i++)
        fill_dp(i,vis2,parent,dp);
    for(int i=0;i<q;i++){
        int x,d;
        cin>>x>>d;
        x=f(x-1,d,dp)+1;
        cout<<(x>0?x:-1)<<"\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}