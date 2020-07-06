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
    long long n,a,b,c;cin>>n>>a>>b>>c;
    if(a<=b-c){
        cout<<n/a<<"\n";
        return;
    }
    else{
        long long ans=0;
        while(n>=b){
            long long ctr=1;
            while(n-(ctr*2)*(b-c)-b>=0) ctr*=2ll;
            ans+=ctr;
            n=n-ctr*(b-c);
        }
        if(n>=a){
            ans+=(n/a);
        }
        cout<<ans<<"\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}