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
    long long n,p,q;
    cin>>n;
    q=(pow_mod(2ll,n+1,MOD)+MOD-1)%MOD;
    q=(q*q+MOD-q)%MOD;

    vector<pair<long long, long long>> states(n);
    long long b=0,w=0,ctr=1;
    for(int i=0;i<n;i++){
        ctr=(ctr*2)%MOD;
        if(i%2==0){
            w=(w+ctr)%MOD;
        }
        else{
            b=(b+ctr)%MOD;
        }
        states[i].first=w;
        states[i].second=b;
    }

    long long ex_w,ex_b,tmp_p;
    p=0;
    for(int i=n-1;i>=0;i--){
        if(i%2==0){
            w=states[n-1-i].first;
            b=states[n-1-i].second;
            ex_w=(states[n-1].first+MOD-w)%MOD;
            ex_b=(states[n-1].second+MOD-b)%MOD;
            tmp_p=((w*w)%MOD)+((ex_b*ex_b)%MOD);
            p=(p+tmp_p)%MOD;
        }
        else{
            b=states[n-1-i].first;
            w=states[n-1-i].second;
            ex_b=(states[n-1].second+MOD-b)%MOD;
            ex_w=(states[n-1].first+MOD-w)%MOD;
            tmp_p=((b*b)%MOD)+((ex_w*ex_w)%MOD);
            p=(p+tmp_p)%MOD;
        }
    }
    p=(p*pow_mod(2ll,MOD-2,MOD))%MOD;
    // cout<<p<<" "<<q<<"\n";
    long long ans=(p*pow_mod(q,MOD-2,MOD))%MOD;
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