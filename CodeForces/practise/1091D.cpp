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

long long f(long long k,long long fk){
    return (((k*k)%MOD)*pow_mod(fk,MOD-2,MOD))%MOD;
}

void solve(){
    long long n;cin>>n;
    vector<long long> fact(n+1,1ll);
    for(int i=2;i<=n;i++) fact[i]=(fact[i-1]*i)%MOD;
    long long ans=(n*fact[n])%MOD;
    for(int i=1;i<=n-1;i++){
        ans=MOD+ans-(fact[n]*f(i*1ll,fact[i+1]))%MOD;
        ans%=MOD;
    }
    cout<<(ans+MOD-n+1)%MOD<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}