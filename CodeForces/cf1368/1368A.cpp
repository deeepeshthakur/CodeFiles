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
    long long a,b,n;
    cin>>a>>b>>n;
    if(a<b) swap(a,b);
    int ans=0;
    while(max(a,b)<=n){
        b+=a;
        if(a<b) swap(a,b);
        ans++;
    }
    cout<<ans<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}