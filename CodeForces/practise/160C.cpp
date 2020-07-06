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
    long long k;
    cin>>n>>k;
    vector<long long> a(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(full(a));
    vector<pair<long long,int>> dp;
    for(int i=0;i<n;i++){
        if(i==0 || a[i]!=a[i-1]){
            dp.pb({a[i],1});
        }
        else{
            dp.back().second++;
        }
    }
    for(int i=0;i<dp.size();i++){
        if(i>0) dp[i].second+=dp[i-1].second;
    }
    int l=0,r=dp.size()-1,mid;
    while(r-l>1){
        mid=(r+l)/2;
        if(1ll*dp[mid].second*n<=k) l=mid;
        else r=mid;
    }
    if(1ll*dp[l].second*n<k) l=r;
    if(l>0) k-=1ll*dp[l-1].second*n;
    int ctr=dp[l].second-(l>0?dp[l-1].second:0);
    pair<int,int> ans{dp[l].first,0};
    for(int i=0;i<n;i++){
        if(ctr<k) k-=ctr;
        else{
            ans.second=a[i];
            i=n+10;
        }
    }
    cout<<ans.first<<" "<<ans.second<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}