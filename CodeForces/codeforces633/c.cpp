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
    vector<long long> a(n,0ll),b(n,0ll);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    long long del=a[0];

    for(int i=0;i<n;i++){
        del=max(a[i],del);
        b[i]=del;
    }
    del=0;
    for(int i=0;i<n;i++){
        del=max(del,b[i]-a[i]);
    }
    if(del==0){
        cout<<0<<"\n";
        return;
    }
    long long ctr=1,mul=1,val=1;;
    while(del>val){
        ctr++;
        mul*=2ll;
        val+=mul;
    }
    cout<<ctr<<"\n";
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