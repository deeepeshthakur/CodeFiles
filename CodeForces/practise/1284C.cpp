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
long long MOD=1e9+7;

void solve(){
    long long n,m;
    cin>>n>>m;
    MOD=m;
    vector<long long> fact(n+10,1ll),f(n+1,1ll);
    for(int i=2;i<fact.size();i++){
        fact[i]=(fact[i-1]*i)%MOD;
    }

    for(int i=n;i>=1;i--){
        f[i]=(fact[i]*fact[n+1-i])%MOD;
        if(i<n){
            f[i]=(f[i]+f[i+1])%MOD;
        }
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        ans+=f[i];
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