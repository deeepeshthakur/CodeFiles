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
    long long x;
    cin>>n>>x;
    vector<long long> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(rfull(a));
    vector<long long> dp(n,0ll);
    for(int i=0;i<n;i++){
        dp[i]=a[i];
        if(i>0){
            dp[i]+=dp[i-1];
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(dp[i]>=x*(i+1)){
            ans=i+1;
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