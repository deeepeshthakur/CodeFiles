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
    int n,m;cin>>n>>m;
    vector<long long> fact(m+1,1ll);
    for(int i=2;i<fact.size();i++) fact[i]=(fact[i-1]*i)%MOD;
    if(n==2){
        cout<<"0\n";return;
    }

    long long ans=1;
    ans*=(pow_mod(2ll,n-3,MOD)*(n-2))%MOD;ans%=MOD;
    ans*=(fact[m]*pow_mod((fact[n-1]*fact[m-n+1])%MOD,MOD-2,MOD))%MOD;ans%=MOD;
    cout<<ans<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}