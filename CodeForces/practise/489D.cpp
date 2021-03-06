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
    int n,m;cin>>n>>m;
    vector<vector<bool>> grid(n,vector<bool>(n,false));
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        grid[x-1][y-1]=true;
        adj[x-1].pb(y-1);
    }

    long long ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            long long tmp=0;
            for(int k=0;k<adj[i].size();k++){
                if(i!=j && adj[i][k]!=i && adj[i][k]!=j && grid[adj[i][k]][j]) tmp++;
            }
            ans+=(tmp*(tmp-1))/2;
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