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

int dfs(int ind,long long dist, long long mn,vector<bool>& vis, vector<vector<pair<int,long long>>>& tr, vector<long long>& a){
    if(vis[ind]){
        vis[ind]=false;
        if(dist-mn>a[ind]) return 0;
        int ans=0;
        mn=min(mn,dist);
        for(int i=0;i<tr[ind].size();i++){
            ans+=dfs(ind,dist+tr[ind][i].second,mn,vis,tr,a);
        }
        return ans;
    }
    return 0;
}

void solve(){
    int n;cin>>n;
    vector<long long> a(n,0ll);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<bool> vis(n,true);
    vector<vector<pair<int,long long>>> tr(n);
    for(int i=0;i<n;i++){
        int p,c;cin>>p>>c;p--;
        tr[p].pb({i,c});
        tr[i].pb({p,c});
    }

    int ans=n-dfs(0,0ll,vis,tr,a,0ll);
    cout<<ans<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}