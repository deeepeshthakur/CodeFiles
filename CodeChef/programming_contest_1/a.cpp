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
    long long aa,bb,cc=0,dd,ee;
    cin>>aa>>bb>>dd>>ee;
    bitset<60> a(aa),b(bb),d(dd),e(ee),c(0);
    
    // cout<<a<<" "<<b<<" "<<d<<" "<<e<<"\n";
    a=(a^b);
    // cout<<a<<"\n";
    for(int i=0;i<60;i++) if(a[i]==0 && e[i]==0 && d[i]==0) c[i]=1;
    // cout<<c<<"\n";
    cout<<c.to_ulong()<<"\n";
    return;
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