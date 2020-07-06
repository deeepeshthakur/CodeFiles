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
long long MOD=int(1e9);

void print_vec(vector<long long>& a, int n=-1){
    n=(n==-1?a.size():n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<(i<n-1?" ":"\n");
}

void solve(){
    int n;
    cin>>n;
    n++;
    vector<vector<long long>> dp(n,vector<long long>(3,0ll));
    for(int i=0;i<n;i++) cin>>dp[i][2];
    long long sm=0;
    for(int i=0;i<n;i++) sm+=dp[i][2];
    dp[0][0]=1;
    for(int i=1;i<n;i++){
        dp[i][0]=min(2ll*sm,2ll*(dp[i-1][0]-dp[i-1][2]));
    }
    dp[n-1][1]=0;
    bool flag=(dp[n-1][0]>=dp[n-1][1]+dp[n-1][2]);
    if(flag) dp[n-1][0]=dp[n-1][1]+dp[n-1][2];
    for(int i=n-2;i>=0&&flag;i--){
        if((dp[i][0]-dp[i][2])*2ll>=dp[i+1][0]){
            if(dp[i][0]>=dp[i+1][0]+dp[i][2]){
                dp[i][1]=dp[i+1][0];
            }
            else{
                dp[i][1]=dp[i][0]-dp[i][2];
            }
            dp[i][0]=dp[i][1]+dp[i][2];
        }
        else{
            flag=false;
        }

    }
    // for(int i=0;i<n;i++){
    //     print_vec(dp[i]);
    // }
    if(flag){
        long long smm=0;
        for(int i=0;i<n;i++) smm+=dp[i][0];
        cout<<smm<<"\n";
    }
    else{
        cout<<"-1\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}