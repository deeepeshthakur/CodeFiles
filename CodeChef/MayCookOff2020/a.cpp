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

long long get_mx_bit(long long y){
    long long ans=0;
    while(y)
        y-=(ans=max(ans,y&(-y)));
    return ans;
}

long long ret(map<pair<long long,long long>,long long>& ht, long long x,long long y){
    if(y==0) return 0;
    long long mx=get_mx_bit(y);
    return ht[{0ll,mx-1}]+mx+ret(ht,0ll,y-mx);
}

void solve(){
    long long n;
    cin>>n;
    for(long long i=1;(1ll<<i)<=n;i++) if(n==(1ll<<i)) {cout<<"-1\n";return;}
    map<pair<long long,long long>,long long> ht;
    ht.insert({{0ll,1ll},1ll});
    ht.insert({{0ll,3ll},4ll});
    long long ans=3;
    if(n>3){
        ans=0;
        for(long long i=8;i/2<=n;i*=2){
            ht[{0ll,i-1}]=i/2+2*ht[{0ll,i/2-1}];
        }
        ans=ret(ht,0ll,n)-1;
    }
    cout<<ans<<endl;

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