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

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<vector<int>> gr(n);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        gr[x-1].pb(y-1);
        gr[y-1].pb(x-1);
    }

    vector<bool> vis(n,true);
    vector<pair<int,int>> v_sort(n,{0,0});
    for(int i=0;i<n;i++){
        v_sort[i].first=v[i];
        v_sort[i].second=i;
    }
    sort(rfull(v_sort));
    long long ans=0;
    for(int i=0;i<n;i++){
        int x=v_sort[i].second;
        for(int j=0;j<gr[x].size();j++){
            if(vis[gr[x][j]]){
                ans+=v[gr[x][j]];
            }
        }
        vis[x]=false;
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