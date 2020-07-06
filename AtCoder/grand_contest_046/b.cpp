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
const long long MOD=998244353ll;

bool is_valid(int x, int y, int a, int b){
    return x>=a && y>=b;
}

void solve(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    vector<vector<long long>> dp(c+1,vector<long long>(d+1,0ll));
    dp[a][b]=1;
    for(int i=a;i<=c;i++){
        for(int j=b;j<=d;j++){
            if(i!=a || j!=b){
                if(is_valid(i-1,j,a,b)) dp[i][j]+=(dp[i-1][j]*j)%MOD;
                if(is_valid(i,j-1,a,b)) dp[i][j]+=(dp[i][j-1]*i)%MOD;
                if(is_valid(i-1,j-1,a,b)) dp[i][j]+=(dp[i-1][j-1]*(MOD-(1ll*(i-1)*(j-1))%MOD))%MOD;
                dp[i][j]%=MOD;
            }
        }
    }
    cout<<dp[c][d]<<"\n";
}   

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}