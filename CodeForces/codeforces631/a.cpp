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
    int n,x;
    cin>>n>>x;
    vector<int> a(n,0),b(min(n,x),0);
    for(int i=0;i<n;i++)
        cin>>a[i];
    vector<int> dp(101,0);
    for(int i=0;i<n;i++){
        dp[a[i]]=1;
    }
    for(int i=0;i<dp.size();i++){
        if(i>0){
            dp[i]+=dp[i-1];
        }
    }

    int ans=0;
    bool flag=true;
    for(int i=0;i<dp.size();i++){
        if(dp[i]+x<i){
            flag=false;
        }
        if(flag){
            ans=max(ans,dp[i]+x);
        }
    }
    cout<<ans<<"\n";
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