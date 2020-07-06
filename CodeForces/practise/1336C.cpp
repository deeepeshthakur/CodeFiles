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
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n,vector<int>(m,0));
    vector<pair<int,int>> dp(n+m-1,{0,0});
    for(int i=0;i<dp.size();i++){
        for(int j=0;j<n;j++){
            int x=i-j;
            if(x>=0 && x<m){
                if(g[j][x]==1) dp[i].second++;
                else dp[i].first++;
            }
        }
    }
    long long ans=0;
    n=dp.size();
    for(int i=0;i<n;i++){
        int a=dp[i].first,b=dp[i].first+dp[i].second;
        if(i<n-1-i){
            a+=dp[n-i-1].first;
            b+=dp[n-i-1]
        }
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