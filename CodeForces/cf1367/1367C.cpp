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
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int> dp(n,n+10);
    for(int i=n-1;i>=0;i--){
        if(s[i]=='1') dp[i]=i;
        else{
            if(i+1<n) dp[i]=dp[i+1];
        }
    }
    int curr=-1;
    int ans=0;
    for(int i=0;i<n;i++){
        if((curr<0 || abs(curr-i)>k) && (dp[i]>=n || abs(dp[i]-i)>k)){
            curr=i;
            ans++;
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