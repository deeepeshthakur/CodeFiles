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
    vector<long long> a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    long long ans=int(1e9);ans*=ans;
    vector<long long> dp(n,0ll);
    long long dp_sum=0;
    for(int i=0;i<n;i++){
        dp[(i+1)%n]=max(0ll,a[(i+1)%n]-b[i]);
        dp_sum+=dp[(i+1)%n];
    }
    for(int i=0;i<n;i++){
        ans=min(ans,a[i]+dp_sum-dp[i]);
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