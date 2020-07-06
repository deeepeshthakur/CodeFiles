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

long long f(long long n, long long r,vector<long long>& a){
    if(n<0 || n<r || r<0) return 0ll;
    return (a[n]*(pow_mod((a[n-r]*a[r])%MOD,MOD-2,MOD)))%MOD;
}

void solve(){
    int n,k;
    cin>>n>>k;
    long long ans=0;
    vector<long long> factorial(n+10,1ll);
    for(int i=2;i<factorial.size();i++){
        factorial[i]=(factorial[i-1]*i)%MOD;
    }
    for(int i=1;i<=n;i++){
        ans+=f(n/i-1,k-1,factorial);
        ans%=MOD;
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