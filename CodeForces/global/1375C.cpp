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

// bool f(int n, vector<int> a){
//     vector<int> dp(n,n+10);
//     for(int i=0;i<n;i++) if(a[i]>=a[0]) dp[i]=i;
//     for(int i=n-1;i>=0;i--) dp[i]=(dp[i]>=n && i+1<n ? dp[i+1]:dp[i]);
//     for(int i=0;i<n;i++) if(a[i]<a[0] && dp[i]>=n) return false;
//     return true;
// }

// bool f1(int n, vector<int> a){
//     vector<int> dp(n,-10);
//     for(int i=0;i<n;i++) if(a[i]<=a.back()) dp[i]=i;
//     for(int i=0;i<n;i++) dp[i]=(dp[i]<0 && i>0 ? dp[i-1]:dp[i]);
//     for(int i=0;i<n;i++) if(a[i]>a.back() && dp[i]<0) return false;
//     return true;
// }



void solve(){
    int n;
    cin>>n;
    vector<int> a(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    if(a[0]<a.back()) cout<<"YES\n";
    else cout<<"NO\n";
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