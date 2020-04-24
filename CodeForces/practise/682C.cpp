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

int dfs(int ind, long long dist, long long mn, vector<bool>& vis, vector<vector<pair<int,long long>>>& tr, vector<long long>& a){
    if(vis[ind]){
        vis[ind]=false;
        if(a[ind]<dist-mn) return 0;
        mn=min(mn,dist);
        int ans=0;
        for(int i=0;i<tr[ind].size();i++){
            ans+=dfs(tr[ind][i].first,dist+tr[ind][i].second,mn,vis,tr,a);
        }
        return ans+1;
    }
    return 0;
}

void solve(){
    int n;cin>>n;
    vector<long long> a(n,0ll);
    for(int i=0;i<n;i++) cin>>a[i];

    vector<vector<pair<int,long long>>> tr(n);
    vector<bool> vis(n,true);
    for(int i=0;i<n-1;i++){
        int p,c;cin>>p>>c;
        p--;
        tr[i+1].pb({p,c});
        tr[p].pb({i+1,c});
    }

    cout<<n-dfs(0,0ll,0ll,vis,tr,a)<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}