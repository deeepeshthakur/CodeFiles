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

void dfs(int ind,int parent, int level, vector<bool>& v,vector<vector<int>>& tr, vector<int>& parray, vector<int>& larray){
    if(v[ind]){
        v[ind]=false;
        parray[ind]=parent;
        larray[ind]=level;
        for(int i=0;i<tr[ind].size();i++){
            dfs(tr[ind][i],ind,level+1,v,tr,parray,larray);
        }
    }
}

void fill_dp(int ind, int lim, vector<bool>& v, vector<int>& parent, vector<bitset<101>>& a, vector<vector<int>>& dp, vector<vector<bitset<101>>>& dp1){
    if(v[ind]){
        if(parent[ind]!=-1){
            fill_dp(parent[ind],lim,v,parent,a,dp,dp1);
            bitset<101> tmp=a[ind];
            dp[ind][0]=parent[ind];
            dp1[ind][0]=(tmp|=a[parent[ind]]);
            for(int i=1;i<lim && dp[ind][i-1]>=0;i++){
                dp[ind][i]=dp[dp[ind][i-1]][i-1];
                dp1[ind][i]=(tmp|=dp1[dp[ind][i-1]][i-1]);
            }
        }
        v[ind]=false;
    }
}

int get_lca(int a,int b, vector<int>& level, vector<int>& parent, vector<vector<int>>& dp){
    if(level[a]>level[b]) swap(a,b);
    while(level[a]!=level[b]){
        int tmp=b;
        for(int i=0;dp[b][i]>=0 && level[dp[b][i]]>=level[a];i++) tmp=dp[b][i];
        b=tmp;
    }
    while(a!=b){
        int x=a,y=b;
        for(int i=0;dp[a][i]>=0 && dp[b][i]>=0 && dp[a][i]!=dp[b][i];i++){
            x=dp[a][i];
            y=dp[b][i];
        }
        a=parent[x];
        b=parent[y];
    }
    return a;
}

int query(bitset<101>& a,int len){
    vector<int> tmp;
    for(int i=0;i<101;i++) if(a[i]==1) tmp.pb(i);
    if(len>tmp.size()) return 0;
    len=1000;
    for(int i=1;i<tmp.size();i++) len=min(len,abs(tmp[i-1]-tmp[i]));
    return len;
}

void solve(){
    int n,q;
    cin>>n>>q;
    vector<vector<int>> tr(n);
    vector<int> parent(n,-1),level(n,0);
    vector<bitset<101>> a(n,bitset<101>(0));
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[i][x]=1;
    }
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        tr[x-1].pb(y-1);
        tr[y-1].pb(x-1);
    }
    int lim=1;
    while((1<<lim)<=2*n) lim++;
    lim+=10;
    vector<vector<int>> dp(n,vector<int>(lim,-1));
    vector<vector<bitset<101>>> dp1(n,vector<bitset<101>>(lim,bitset<101>(0)));
    vector<bool> vis(n,true),vis1(n,true);
    dfs(0,-1,1,vis,tr,parent,level);
    for(int i=0;i<n;i++)
        fill_dp(i,lim,vis1,parent,a,dp,dp1);

    for(int i=0;i<q;i++){
        int x,y;
        cin>>x>>y;
        x--;y--;
        int lca=get_lca(x,y,level,parent,dp);
        int len=level[x]+level[y]-2*level[lca]+1;
        bitset<101> ans(0);
        while(level[x]>level[lca]){
            ans|=a[x];
            int mtp=x,ind=-1;
            for(int i=0;dp[x][i]>=0 && level[dp[x][i]]>level[lca];i++){
                mtp=dp[x][i];
                ind=i;
            }
            if(ind>=0) ans|=dp1[x][ind];
            x=parent[mtp];
        }
        x=y;
        while(level[x]>level[lca]){
            ans|=a[x];
            int mtp=x,ind=-1;
            for(int i=0;dp[x][i]>=0 && level[dp[x][i]]>level[lca];i++){
                mtp=dp[x][i];
                ind=i;
            }
            if(ind>=0) ans|=dp1[x][ind];
            x=parent[mtp];
        }
        ans|=a[lca];
        cout<<query(ans,len)<<"\n";
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