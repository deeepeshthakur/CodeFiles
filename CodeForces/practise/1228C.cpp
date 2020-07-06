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

void print_vec(vector<long long>& a, int n=-1){
    n=(n==-1?a.size():n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<(i<n-1?" ":"\n");
}

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

void solve(){
    long long x,n;
    cin>>x>>n;
    vector<bool> is_prime(int(1e5),true);is_prime[0]=is_prime[1]=false;
    vector<long long> prime;
    for(int i=0;i<is_prime.size();i++){
        if(is_prime[i]){
            prime.pb(i);
            int j=i;
            while(1ll*i*j<is_prime.size()){
                is_prime[i*j]=false;
                j++;
            }
        }
    }

    vector<long long> pfx;
    for(int i=0;i<prime.size();i++){
        if(x%prime[i]==0){
            pfx.pb(prime[i]);
            while(x%prime[i]==0) x/=prime[i];
        }
    }
    if(x>1) pfx.pb(x);
    unsigned long long ans=1;
    for(int i=0;i<pfx.size();i++){
        unsigned long long fc=pfx[i],ctr=0,mul=fc,curr;
        while(n/mul>=fc) mul*=fc;
        while(mul>=fc){
            ctr+=(n/mul)%(MOD-1);
            ctr%=(MOD-1);
            mul/=fc;
        }
        ans*=pow_mod(fc,ctr,MOD);
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