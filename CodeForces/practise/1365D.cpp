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

vector<pair<int,int>> d{{0,1},{0,-1},{1,0},{-1,0}};

bool is_valid(int x, int y, int n, int m){
    return x>=0 && y>=0 && x<n && y<m;
}

bool is_bad_n(int x,int y, int n, int m, vector<string>& g){
    for(int i=0,xx,yy;i<4;i++){
        xx=x+d[i].first;yy=y+d[i].second;
        if(is_valid(xx,yy,n,m) && g[xx][yy]=='B') return true;
    }
    return false;
}

void dfs(int x, int y, int n, int m, vector<vector<bool>>& g, vector<vector<bool>>& v){
    if(!v[x][y]){
        v[x][y]=true;
        for(int i=0,xx,yy;i<4;i++){
            xx=x+d[i].first;yy=y+d[i].second;
            if(is_valid(xx,yy,n,m) && g[xx][yy])
                dfs(xx,yy,n,m,g,v);
        }
    }
}

bool find_reach(int n,int m, vector<vector<bool>>& g, vector<vector<bool>>& v){
    dfs(n-1,m-1,n,m,g,v);
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<string> grid(n);
    for(int i=0;i<n;i++) cin>>grid[i];
    int g=0,b=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(grid[i][j]=='G') g++;
            if(grid[i][j]=='B') b++;
        }
    bool flag=true;
    if(g>0){
        for(int i=0;i<n;i++) for(int j=0;j<m;j++)
            if(grid[i][j]=='.' && is_bad_n(i,j,n,m,grid)) grid[i][j]='#';
        vector<vector<bool>> g(n,vector<bool>(m,true)),v(n,vector<bool>(m,false));

        for(int i=0;i<n;i++) for(int j=0;j<m;j++) g[i][j]=(grid[i][j]!='#');
        if(g[n-1][m-1]) find_reach(n,m,g,v);
        // find_reach(n,m,g,v);
        for(int i=0;i<n;i++) for(int j=0;j<m;j++){
            if(grid[i][j]=='B') if(v[i][j]) flag=false;
            if(grid[i][j]=='G') if(!v[i][j]) flag=false;
        }
    }
    if(flag) cout<<"Yes\n";
    else cout<<"No\n";
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