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
    int n,k;
    cin>>n>>k;
    vector<vector<long long>> dp(n,vector<long long>(k,1ll));
    for(int j=1;j<k;j++){
        long long sm=0;
        for(int i=0;i<n;i++)
            dp[i][j]=sm=(sm+dp[i][j-1])%MOD;
    }
    long long ans=0;
    for(int i=0;i<n;i++) ans=(ans+dp[i][k-1])%MOD;
    cout<<ans<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}