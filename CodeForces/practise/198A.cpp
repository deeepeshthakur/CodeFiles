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
    long long k,b,n,t;
    cin>>k>>b>>n>>t;
    long long ans=0;
    if(k==1){
        ans=n-(t-1)/b;
    }
    else{
        b=(k*t+b-t)/(k+b-1);
        long long mul=1;
        while(b>=mul*k){
            ans++;
            mul*=k;
        }
        ans=n-ans;
    }
    cout<<max(0ll,ans)<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}