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

long long f(long long l){
    return l*(l-1)/2;
}

void solve(){
    int n;cin>>n;
    vector<int> a(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> bit_xordp(n,0);
    vector<pair<int,int>> dp(1<<20,{0,0});
    dp[0].first++;
    for(int i=0;i<n;i++){
        bit_xordp[i]=a[i];
        if(i>0) bit_xordp[i]^=bit_xordp[i-1];
        if((i+1)%2==0) dp[bit_xordp[i]].first++;
        else dp[bit_xordp[i]].second++;
    }
    long long ans=0;
    for(int i=0;i<dp.size();i++){
        // if(dp[i].first+dp[i].second>0) cout<<i<<" "<<dp[i].first<<" "<<dp[i].second<<"\n";
        ans+=f(1ll*dp[i].first)+f(1ll*dp[i].second);
    }
    cout<<ans<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}