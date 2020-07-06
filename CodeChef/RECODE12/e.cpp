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
const long long MOD=163577857ll;

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
    return ans%mod;
}

long long ncr(int n, int r, vector<long long>& f){
    if(n<r || r<0 || n<0) return 0ll;
    return (f[n]*pow_mod((f[n-r]*f[r])%MOD,MOD-2,MOD))%MOD;
}

long long f(int x, int a, int b, int c, vector<long long>& f){
    if(x>a) return 0ll;
    long long ans=1;
    ans=(pow_mod(2ll,1ll*c,MOD)*ncr(a+b,a-x,f))%MOD;
    return ans%=MOD;
}

void solve(){
    int n;cin>>n;
    int a=0,b=0,c=0;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        if(x==1) a++;
        if(x==0) c++;
        if(x==-1) b++;
    }

    vector<long long> fact(n+100,1ll);
    for(int i=2;i<fact.size();i++){
        fact[i]=(fact[i-1]*i)%MOD;
    }

    vector<long long> ans(2*n+1,0ll);
    for(int i=0;i<ans.size();i++){
        int x=i-n;
        if(x<0 && abs(x)<=b) ans[i]=f(abs(x),b,a,c,fact);
        if(x>0 && x<=a) ans[i]=f(x,a,b,c,fact);
        if(x==0) ans[i]=((pow_mod(2ll,1ll*c,MOD)*ncr(a+b,min(a,b),fact))%MOD+MOD-1)%MOD;
    }

    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    cout<<"\n";
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