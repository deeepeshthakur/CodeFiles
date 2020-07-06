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
    vector<vector<int>> grid(n,vector<int>(m,0));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>grid[i][j];
    int x=0,y=0;
    for(int i=0;i<n;i++){
        bool flag=true;
        for(int j=0;j<m;j++) if(grid[i][j]==1) flag=false;
        x+=(flag)?1:0;
    }

    for(int i=0;i<m;i++){
        bool flag=true;
        for(int j=0;j<n;j++) if(grid[j][i]==1) flag=false;
        y+=(flag)?1:0;
    }
    x=min(x,y);
    if(x%2==0) cout<<"Vivek\n";
    else cout<<"Ashish\n";
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