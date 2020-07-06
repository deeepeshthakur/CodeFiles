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
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    vector<string> grid(n);
    for(int i=0;i<n;i++) cin>>grid[i];
    y=min(y,2*x);
    long long ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            // if(grid[i][j]=='.' && i+1<n && grid[i+1][j]=='.'){
            //     ans+=y;
            //     grid[i][j]='*';
            //     grid[i+1][j]='*'; 
            // }
            if(grid[i][j]=='.' && j+1<m && grid[i][j+1]=='.'){
                ans+=y;
                grid[i][j]='*';
                grid[i][j+1]='*'; 
            }
            if(grid[i][j]=='.'){
                ans+=x;
                grid[i][j]='*';
            }            
        }
    }
    cout<<ans<<"\n";
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