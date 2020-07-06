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
    int n;cin>>n;
    vector<long long> a(n,0ll);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(full(a));
    vector<long long> dp(int(1e5)+1,0ll);

    for(int i=0;i<n;i++){
        if(a[i]<dp.size()){
            dp[a[i]]++;
        }
    }
    for(int i=0;i<dp.size();i++){
        if(i>0){
            dp[i]+=dp[i-1];
        }
    }
    long long ans=0,mul=1;
    bool flag=true;
    for(int i=1;i<dp.size()&&flag;i++){
        if(i==1 && dp[i]==0){
            flag=false;
        }
        if(i>1 && dp[i]==dp[i-1]){
            flag=false;
        }
        ans+=(((1ll*i)*(pow_mod(2ll,n-dp[i],MOD)+MOD)%MOD)*mul)%MOD;
        ans%=MOD;
        if(i==1&&dp[i]>0){
            mul*=(pow_mod(2ll,dp[i],MOD)+MOD-1)%MOD;
            mul%=MOD;
        }
        if(i>1 && dp[i]-dp[i-1]>0){
            mul*=(pow_mod(2ll,dp[i]-dp[i-1],MOD)+MOD-1)%MOD;
            mul%=MOD;
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