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
    int k;
    cin>>k;
    vector<long long> fact(5001,1ll);
    for(int i=2;i<fact.size();i++){
        fact[i]=(1ll*i*fact[i-1])%MOD;
    }
    long long ans=1,n=0;
    for(int i=0;i<k;i++){
        int x;
        cin>>x;
        if(i>0){
            ans*=((fact[n+x-1]*pow_mod(fact[n]*fact[x-1],MOD-2,MOD))%MOD);
            ans%=MOD;
        }
        n+=x;
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