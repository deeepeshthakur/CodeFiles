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
    int n;cin>>n;
    long long sm=0;
    vector<long long> a(n,0ll),dpl(n,0ll),dpr(n,0ll);
    for(int i=0;i<n;i++){
        cin>>a[i];
        sm+=abs(a[i]);
    }
    if(n==1){
        cout<<a[0]<<"\n";
        return;
    }

    for(int i=0;i<n;i++){
        dpl[i]=a[i];
        dpr[n-1-i]=a[n-1-i];
        if(i>0){
            dpl[i]=min(dpl[i],dpl[i-1]);
            dpr[n-1-i]=min(dpr[n-i-1],dpr[n-i]);
        }
    }
    long long ans=sm-(1<n?(dpr[1]+abs(dpr[1])):0ll)+(a[0]-abs(a[0]));
    for(int i=0;i<n;i++){
        ans=max(ans,sm+(a[i]-abs(a[i]))-(i>0?(dpl[i-1]+abs(dpl[i-1])):0)-(i+1<n?(dpr[i+1]+abs(dpr[i+1])):0));
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