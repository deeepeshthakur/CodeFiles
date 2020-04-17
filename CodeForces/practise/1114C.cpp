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

void solve(){
    long long n,b,tmpb;cin>>n>>b;tmpb=b;
    vector<bool> is_prime(int(1e6)+10,true);
    is_prime[0]=false;is_prime[1]=false;
    vector<long long> fact,mul; 
    for(int i=0;i<is_prime.size();i++){
        if(is_prime[i]){
            if(b%i==0) {fact.pb(i*1ll);mul.pb(0ll);}
            int j=i; while(1ll*j*i<is_prime.size()) {is_prime[i*j]=false;j++;}
        }
    }
    for(int i=0;i<fact.size();i++){
        while(tmpb%fact[i]==0){
            mul[i]++;tmpb/=fact[i];
        }
    }
    if(tmpb>1){fact.pb(tmpb);mul.pb(1ll);}
    vector<long long> ans(fact.size(),0);
    for(int i=0;i<fact.size();i++){
        long long x=fact[i];
        while(x<=n){
            ans[i]+=(n/x);
            if((n/x)>=fact[i]) x*=fact[i];
            else x=n+1;
        }
    }
    long long mx=ans[0]/mul[0];
    for(int i=0;i<fact.size();i++){
        mx=min(ans[i]/mul[i],mx);
    }
    cout<<mx<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}