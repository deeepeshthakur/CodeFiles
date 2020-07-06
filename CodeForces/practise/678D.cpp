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
    long long a,b,x,n;
    cin>>a>>b>>n>>x;
    if(a==1){
        cout<<(x+((n%MOD)*b)%MOD)%MOD<<"\n";
        return;
    }
    long long ans=0;
    long long an=pow_mod(a,n,MOD),anb=(((MOD-1+an)%MOD)*b)%MOD,am1=pow_mod(a+MOD-1,MOD-2,MOD);
    ans=((an*x)%MOD) + ((anb*am1)%MOD);
    cout<<ans%MOD<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}