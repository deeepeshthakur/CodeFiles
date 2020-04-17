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
    int n;cin>>n;
    vector<int> a(n,0);for(int i=0;i<n;i++) {cin>>a[i]; a[i]--;}
    vector<vector<int>> dp(n,vector<int>(26,0));
    for(int i=0;i<n;i++){
        dp[i][a[i]]++;
        if(i>0) for(int j=0;j<26;j++) dp[i][j]+=dp[i-1][j];
    }

    int ans=0; for(int i=0;i<26;i++) ans=max(ans,dp[n-1][i]);
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int tmp=0,tmp2=0;
            for(int k=0;k<26;k++){
                tmp=max(tmp,dp[j][k]-(i>0?dp[i-1][k]:0));
                tmp2=max(tmp2,min((i>0?dp[i-1][k]:0),dp[n-1][k]-dp[j][k]));
            }
            ans=max(ans,tmp+2*tmp2);
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