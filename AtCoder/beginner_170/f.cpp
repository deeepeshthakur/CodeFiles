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

bool is_valid(int x, int y, int n, int m){
    return x>=0 && y>=0 && x<n && y<m;
}

void bfs(int x, int y, int n, int m, int k, vector<vector<bool>>& v, vector<string>& gr, vector<vector<int>>& dp, queue<pair<int,int>>& q){
    if(v[x][y]){
        v[x][y]=false;
        for(int i=1;i<=k;i++){
            int xx=x+i,yy=y;
            if(!is_valid(xx,yy,n,m) || dp[xx][yy]<=dp[x][y] || gr[xx][yy]=='@'){
                break;
            }
            else{
                dp[xx][yy]=dp[x][y]+1;
                q.push({xx,yy});
            }
        }
        for(int i=1;i<=k;i++){
            int xx=x-i,yy=y;
            if(!is_valid(xx,yy,n,m) || dp[xx][yy]<=dp[x][y] || gr[xx][yy]=='@'){
                break;
            }
            else{
                dp[xx][yy]=dp[x][y]+1;
                q.push({xx,yy});
            }
        }

        for(int i=1;i<=k;i++){
            int xx=x,yy=y+i;
            if(!is_valid(xx,yy,n,m) || dp[xx][yy]<=dp[x][y] || gr[xx][yy]=='@'){
                break;
            }
            else{
                dp[xx][yy]=dp[x][y]+1;
                q.push({xx,yy});
            }
        }
        for(int i=1;i<=k;i++){
            int xx=x,yy=y-i;
            if(!is_valid(xx,yy,n,m) || dp[xx][yy]<=dp[x][y] || gr[xx][yy]=='@'){
                break;
            }
            else{
                dp[xx][yy]=dp[x][y]+1;
                q.push({xx,yy});
            }
        }
    }
}


void solve(){
    int h,w,k;
    cin>>h>>w>>k;
    int x,y,a,b;
    cin>>x>>y>>a>>b;
    x--;y--;a--;b--;
    vector<string> gr(h);
    for(int i=0;i<h;i++) cin>>gr[i];
    vector<vector<int>> dp(h,vector<int>(w,MOD));
    vector<vector<bool>> v(h,vector<bool>(w,true));
    dp[x][y]=0;
    queue<pair<int,int>> q;    
    q.push({x,y});
    while(!q.empty()){
        x=q.front().first;
        y=q.front().second;
        q.pop();
        bfs(x,y,h,w,k,v,gr,dp,q);
    }

    // for(int i=0;i<h;i++){
    //     for(int j=0;j<w;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    if(v[a][b]){
        cout<<"-1\n";
    }
    else{
        cout<<dp[a][b]<<"\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}