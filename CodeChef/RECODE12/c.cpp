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
    long long n,k;cin>>n>>k;
    if(n==0){
        cout<<(k*k-k)%MOD<<"\n";
        return;
    }
    if(k==1){
        cout<<(n*n)%MOD<<"\n";
        return;
    }
    long long t=(k%2==0?k/2:(k-1)/2)+n-1;
    long long ans=(t*t+t)%MOD;
    if(k%2==0){
        ans+=n;
    }
    else{
        ans+=2*t+2-n;
    }
    ans%=MOD;
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