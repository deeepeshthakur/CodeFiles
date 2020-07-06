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
    long long k=0;
    cin>>n>>k;
    vector<long long> a(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> v;
    for(int i=0;i<n;i++){
        if((k|a[i])!=k) v.pb(i);
    }
    bool flag=true;
    for(int i=0;i<v.size();i++){
        if(v[i]<n-1){
            if(v[i+1]-v[i]==1){
                flag=false;
            }
        }
        else{
            if(v[0]==0) flag=false;
        }
    }
    for(int i=0;i<v.size();i++) a[v[i]]=0;
    long long ans=0;
    for(int i=0;i<n;i++) ans=(ans|a[i]);
    vector<bool> vis(n,true); for(int i=0;i<v.size();i++) vis[v[i]]=false;
    vector<pair<long long,long long>> dp(n,{0,0});
    for(int i=0;i<n;i++){
        dp[i].first=a[i];
        if(i) dp[i].first=(dp[i].first|dp[i-1].first);
    }
    for(int i=n-1;i>=0;i--){
        dp[i].second=a[i];
        if(i+1<n) dp[i].second=(dp[i].second|dp[i+1].second);
    }
    bool f1=(v.size()>0);
    for(int i=0;i<n&&!f1;i++){
        if(vis[i]&&k==((i>0?dp[i-1].first:0)|(i+1<n?dp[i+1].second:0))){
            f1=true;
            v.pb(i);
            vis[i]=false;
        }
    }
    flag=(flag&&(ans==k));

    if(flag&&f1){
        for(int i=0;i<v.size();i++) cout<<v[i]+1<<" ";
        for(int i=0;i<n;i++) if(vis[(v.back()+i)%n]) cout<<(v.back()+i)%n+1<<" ";
        cout<<"\n";
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