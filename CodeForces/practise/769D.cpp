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
    int n,k;cin>>n>>k;
    vector<int> a(int(1e4)+1,0);
    for(int i=0;i<n;i++){int x;cin>>x;a[x]++;}
    vector<int> res;
    for(int i=0;i<(1<<15);i++) if(bitset<14>(i).count()==k) res.pb(i);
    if(k==0){
        long long atmp=0;
        for(int i=0;i<a.size();i++) atmp+=(1ll*a[i]*a[i]-a[i])/2;
        cout<<atmp<<"\n";
        return;
    }
    long long ans=0;
    for(int i=0;i<a.size();i++){
        if(a[i]>0)
            for(int j=0;j<res.size();j++)
                if((i^res[j])<a.size()) ans+=(1ll*a[(i^res[j])]*a[i]);
    }
    cout<<ans/2<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}