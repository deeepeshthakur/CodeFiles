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
    long long n,m,k;
    cin>>n>>m>>k;
    if(2*n*m%k==0){
        long long x=n/__gcd(n,k);
        k/=__gcd(n,k);
        long long y=m/__gcd(m,k);
        k/=__gcd(m,k);
        long long tmp=2/__gcd(2ll,k);
        if(tmp*x<=n) x*=tmp;
        else y*=tmp;
        cout<<"YES\n";
        cout<<0<<" "<<0<<"\n";
        cout<<x<<" "<<0<<"\n";
        cout<<0<<" "<<y<<"\n";
        return;
    }

    cout<<"NO\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}