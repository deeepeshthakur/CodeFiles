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
const long long MOD=998244353ll;

void dfs(int ind,int par,vector<bool>& vis, vector<vector<int>>& tr, vector<int>& sc){
    if(vis[ind]){
        vis[ind]=false;
        sc[ind]=par;
        for(int i=0;i<tr[ind].size();i++) dfs(tr[ind][i],-1*par,vis,tr,sc);
    }
}

long long pow_mod(long long a, long long b, long long mod){
    long long ans=1;
    a%=mod;
    while(b>0){
        if(b&1){
            ans*=a;
            ans%=mod;
        }
        b=b>>1;
        a=(a*a)%mod;
    }
    return ans%mod;
}

void solve(){
    int n,m;cin>>n>>m;
    vector<pair<int,int>> edges(m,{0,0});
    vector<vector<int>> tr(n);
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        x--;y--;
        tr[x].pb(y);
        tr[y].pb(x);
        edges[i]={x,y};
    }

    vector<int> sc(n,0);
    vector<bool> vis(n,true);
    int ctr=0;
    for(int i=0;i<n;i++){
        if(vis[i]){
            dfs(i,ctr+1,vis,tr,sc);
            ctr++;
        }
    }
    bool flag=true;
    for(int i=0;i<m;i++) if(1ll*sc[edges[i].first]*sc[edges[i].second]>0) flag=false;
    if(!flag){
        cout<<0<<"\n";
        return;
    }
    vector<pair<int,int>> v(ctr,{0,0});
    for(int i=0;i<n;i++){
        if(sc[i]>0) v[sc[i]-1].first++;
        else v[abs(sc[i])-1].second++;
    }
    long long ans=1;
    for(int i=0;i<v.size();i++){
        if(v[i].first+v[i].second>0){
            ans*=(pow_mod(2ll,1ll*v[i].first,MOD)+pow_mod(2ll,1ll*v[i].second,MOD))%MOD;
            ans%=MOD;
        }
    }
    cout<<ans%MOD<<"\n";
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