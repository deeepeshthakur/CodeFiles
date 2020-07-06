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
    vector<pair<int,int>> a(n,{0,0});
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    long long ans=0;
    for(int i=0;i<n;i++){
        ans+=(a[i].second-a[i].first+1);
        ans%=MOD;
    }
    cout<<ans<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t=1;
    while(t--){
        solve();
    }
    return 0;
}