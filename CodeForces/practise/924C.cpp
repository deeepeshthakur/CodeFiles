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
    vector<int> m(n,0),dp(n,0);
    for(int i=0;i<n;i++) cin>>m[i];
    for(int i=0;i<n;i++) dp[i]=max(m[i]+1,(i>0?dp[i-1]:0));
    for(int i=n-1;i>=0;i--) dp[i]=max(dp[i],(i+1<n?dp[i+1]-1:0));
    long long sm=0;
    for(int i=0;i<n;i++) sm+=max(dp[i]-m[i]-1,0);
    cout<<sm<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}