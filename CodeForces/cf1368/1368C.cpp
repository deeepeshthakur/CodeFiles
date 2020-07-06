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
    int n;
    cin>>n;
    vector<vector<int>> dp(5,vector<int>(2*n+3,0));
    for(int i=0;i<dp[2].size();i++) dp[2][i]=1;
    dp[0][0]=dp[1][0]=dp[0][1]=dp[0][2]=1;

    for(int i=2;i+2<dp[0].size();i+=2)
        for(int j=0;j<5;j++) dp[j][i]=1;
    
    for(int i=2;i+1<=n;i+=2){
        for(int j=2*i;j<=2*i+2;j++) dp[0][j]=1;
    }

    for(int i=1;i+1<=n;i+=2){
        for(int j=2*i;j<=2*i+2;j++) dp[4][j]=1;
    }

    int lst=2*n+2;
    if(n%2==1){
        dp[3][lst]=dp[4][lst]=dp[4][lst-1]=dp[4][lst-2]=1;
    }
    else{
        dp[1][lst]=dp[0][lst]=dp[0][lst-1]=dp[0][lst-2]=1;
    }
    vector<pair<int,int>> ans;
    for(int i=0;i<5;i++)
        for(int j=0;j<dp[i].size();j++)
            if(dp[i][j]==1) ans.pb({i,j});
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].first<<" "<<ans[i].second<<"\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}