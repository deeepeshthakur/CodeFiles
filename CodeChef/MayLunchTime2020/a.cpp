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

long long f1(long long n){
    return (n*n)%MOD;
}

long long f2(long long n){
    return ((((n*n+n)%MOD)*(n*4ll+2ll))%MOD*pow_mod(3ll,MOD-2,MOD))%MOD;
}

void solve(){
    long long n;
    cin>>n;
    long long ans=0;
    long long en,on;
    if(n%2==0) on=en=n/2;
    else on=(en=n/2)+1;
    ans=(f1(on)+f2(en))%MOD;
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