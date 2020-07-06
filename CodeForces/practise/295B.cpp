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

void print_vec(vector<long long>& a, int n=-1){
    n=(n==-1?a.size():n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<(i<n-1?" ":"\n");
}

void solve(){
    int n;
    cin>>n;
    vector<vector<long long>> adj(n,vector<long long>(n,10ll*MOD)),grid(n,vector<long long>(n,0));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>grid[i][j];
    vector<int> x(n,0);
    for(int i=0;i<n;i++){cin>>x[n-1-i];x[n-1-i]--;}

    vector<long long> ans(n,0);
    vector<bool> vis(n,false);
    long long inf=(9ll*MOD);
    for(int k=0;k<n;k++){
        int y=x[k];
        vis[y]=true;

        for(int i=0;i<n;i++){
            if(vis[i]){
                adj[i][y]=grid[i][y];
                adj[y][i]=grid[y][i];
            }
        }

        for(int i=0;i<n;i++){
            if(i!=y && vis[i])
                for(int j=0;j<n;j++){
                    if(i!=j && j!=y && vis[j]){
                        adj[y][i]=min(adj[y][i],adj[y][j]+adj[j][i]);
                        adj[i][y]=min(adj[i][y],adj[i][j]+adj[j][y]);
                    }
                }
        }

        for(int i=0;i<n;i++){
            if(i!=y && vis[i])
                for(int j=0;j<n;j++){
                    if(i!=j && j!=y && vis[j]){
                        adj[i][j]=min(adj[i][y]+adj[y][j],adj[i][j]);
                    }
                }
        }

        for(int i=0;i<n;i++){
            if(vis[i])
            for(int j=0;j<n;j++){
                if(vis[j]){
                    ans[k]+=adj[i][j];
                }
            }
        }
    }

    for(int i=n-1;i>=0;i--) cout<<ans[i]<<" ";
    cout<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}