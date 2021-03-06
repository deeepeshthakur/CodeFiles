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
    int n;
    cin>>n;
    vector<int> a(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    int po=0,pe=0,ee=0,eo=0;
    for(int i=0;i<n;i++){
        if(i%2==1) po++;
        if(a[i]%2==1) eo++;
    }
    ee=n-eo;
    pe=n-po;
    if(pe==ee && po==eo){
        int ans=0;
        for(int i=0;i<n;i++) if(i%2!=a[i]%2) ans++;
        cout<<ans/2<<"\n";
    }
    else{
        cout<<"-1\n";
    }
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