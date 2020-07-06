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

long long pow_mod(long long a, long long b, long long mod){
    long long ans=1;
    a%=mod;
    while(b>0){
        if(b&1){
            ans*=a;
            ans%=mod;
        }
        b=b>>1;
        a=(a*a)%mod;
    }
    return ans;
}

void solve(){
    int n,s;
    cin>>n>>s;
    vector<int> a(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<bitset<3001>> dp(3001,bitset<3001>(0));
    dp[0][0]=1;
    bitset<3001> tmp;
    for(int i=0;i<n;i++){
        for(int j=0;j<=s;j++){
            if(a[i]+j<=s){
                if(a[i]+j==s){
                    tmp=(dp[j]<<1);
                }
                else{
                    dp[a[i]+j]|=(dp[j]<<1);
                }
            }
        }
    }
    long long ans=0;
    for(int i=0;i<=s;i++) cout<<dp[i]<<"\n";
    for(int i=1;i<n;i++){
        if(dp[s][i]==1){
            cout<<i<<"\n";
            ans+=pow_mod(2ll,1ll*n-i,MOD);
            ans%=MOD;
        }
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