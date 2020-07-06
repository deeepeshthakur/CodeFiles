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
    long long k,n;
    string a;
    cin>>a;
    n=a.size();
    cin>>k;
    long long mul=(((pow_mod(2ll,n*k,MOD)+MOD-1)%MOD)*pow_mod((pow_mod(2ll,n,MOD)+MOD-1)%MOD,MOD-2,MOD))%MOD,ans=0;
    for(int i=0;i<n;i++){
        if(a[i]=='0' || a[i]=='5'){
            ans+=pow_mod(2ll,i*1ll,MOD);
            ans%=MOD;
        }
    }
    cout<<(ans*mul)%MOD<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}