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
int N,M;
vector<pair<int,int>> d{{0,1},{0,-1},{1,0},{-1,0}};
inline bool is_valid(int a, int b){
    return a>-1 && b>-1 && a<N && b<M;
}

int dfs(int x, int y, int a, int b, vector<vector<bool>>& grid, 
        vector<vector<bool>>& vis, vector<vector<pair<int,int>>>& parent){
    if(is_valid(x,y)&&vis[x][y]){
        vis[x][y]=false;
        parent[x][y]={a,b};
        int tmp=0;
        for(int i=0;i<4;i++){
            if(is_valid(x+d[i].first,y+d[i].second)){
                if(grid[x+d[i].first][y+d[i].second]) tmp+=dfs(x+d[i].first,y+d[i].second,a,b,grid,vis,parent);
                else tmp+=1;    
            }
        }
        return tmp;
    }
    return 0;
}

void solve(){
    int n,m,k;cin>>n>>m>>k;N=n;M=m;
    vector<vector<bool>> grid(n,vector<bool>(m,true)),vis(n,vector<bool>(m,true));;
    vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>>(m,{0,0}));
    vector<vector<int>> ans(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        string s;cin>>s;
        for(int j=0;j<m;j++){
            if(s[j]=='*') grid[i][j]=false;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]){
                if(vis[i][j]) ans[i][j]=dfs(i,j,i,j,grid,vis,parent);
                else ans[i][j]=ans[parent[i][j].first][parent[i][j].second];
            }
        }
    }
    for(int i=0;i<k;i++){
        int x,y;cin>>x>>y;
        cout<<ans[x-1][y-1]<<"\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}