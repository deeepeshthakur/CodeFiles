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

void print_vec(vector<bool>& a, int n=-1){
    n=(n==-1?a.size():n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<(i<n-1?" ":"\n");
}

void solve(){
    int n,m;cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(n,-1));
    for(int i=0;i<m;i++){
        int x,y;
        char c;
        cin>>x>>y>>c;
        grid[x-1][y-1]=int(c-'a');
    }

    vector<vector<vector<bool>>> dp(n,vector<vector<bool>>(n,vector<bool>(27,false)));
    bool flag=false;
    for(int c=25;c>=0;c--){
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                bool flag=false;
                for(int x=0;x<n;x++){
                    bool f1=false;
                    if(grid[i][x]==c){
                        f1=true;
                        for(int y=c;y<=26;y++){
                            if(dp[j][x][y]) f1=false;
                            if(i==0 && j==1 && c==1 && f1){
                                cout<<x<<" "<<y<<"\n";
                            }
                        }
                    }
                    if(f1) flag=true;
                }
                dp[i][j][c]=flag;
                if(dp[i][j][c]) cout<<"----------"<<i+1<<" "<<j+1<<" "<<char(c+'a')<<"\n";
            }
    }
    
    for(int i=0;i<n;i++) {for(int j=0;j<n;j++) print_vec(dp[i][j]); cout<<"\n";}
    
    vector<vector<bool>> ans(n,vector<bool>(n,false));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<27;k++)
                if(dp[i][j][k]) ans[i][j]=true;
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) cout<<(ans[i][j]?'A':'B')<<(j+1<n?"":"\n");
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}