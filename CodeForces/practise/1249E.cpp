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
    int n,c;cin>>n>>c;
    vector<int> a(n-1,0),b(n-1,0);
    for(int i=0;i<n-1;i++) cin>>a[i];
    for(int i=0;i<n-1;i++) cin>>b[i];
    vector<pair<long long,long long>> dp(n,{100ll*MOD,100ll*MOD});
    dp[0]={c,0};
    for(int i=1;i<n;i++){
        dp[i].first=min(dp[i-1].first+b[i-1],dp[i-1].second+c+b[i-1]);
        dp[i].second=min(dp[i-1].first,dp[i-1].second)+a[i-1];
    }
    for(int i=0;i<n;i++){
        cout<<min(dp[i].first,dp[i].second)<<" ";
    }
    cout<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}