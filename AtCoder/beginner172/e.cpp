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

long long ncr(int n, int r, vector<long long>& f, vector<long long>& inv){
    if(r<0 || n<0 || r>n) return 0ll;
    return (f[n]*((inv[n-r]*inv[r])%MOD))%MOD;
    // cout<<tmp<<"\n";
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<long long> fct(m+10,1),inv(m+10,1);
    for(int i=2;i<fct.size();i++) fct[i]=(fct[i-1]*i)%MOD;
    for(int i=0;i<inv.size();i++) inv[i]=pow_mod(fct[i],MOD-2,MOD);
    vector<long long> deran(m+10,1);
    for(int i=1;i<deran.size();i++) deran[i]=((deran[i-1]*i)%MOD + MOD + (i%2==0? 1ll : -1ll))%MOD;
    long long ans=0,tmp=0;
    for(int i=0;i<=n && i+n<=m;i++){
        tmp=0;
        tmp=(((ncr(m,n+i,fct,inv)*ncr(n+i,i,fct,inv))%MOD))%MOD;
        tmp*=(((fct[n]*deran[n])%MOD)*((fct[i]*fct[i])%MOD))%MOD;
        tmp%=MOD;
        ans=(ans+tmp)%MOD;
        // cout<<ans<<"\n";
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