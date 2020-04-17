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
    int n,h,l,r;cin>>n>>h>>l>>r;
    vector<vector<int>> dp(n+1,vector<int>(h,0));
    vector<int> a(n,0);for(int i=0;i<n;i++) cin>>a[i];
    for(int i=l;i<=r;i++) dp[n][i]=1;

    for(int i=n-1;i>=0;i--){
        for(int j=0;j<h;j++){
            if(l<=j && j<=r) dp[i][j]=1;
            dp[i][j]+=max(dp[i+1][(j+a[i])%h],dp[i+1][(j+a[i]-1)%h]);
        }
    }
    int ans=dp[0][0]-(l<=0 && 0<=r ? 1:0);
    // for(int i=0;i<h;i++) ans=max(ans,dp[0][i]);
    cout<<ans<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}