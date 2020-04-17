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
const long long MOD=998244353ll;

void print_vec(vector<long long>& a, int n=-1){
    n=(n==-1?a.size():n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<(i<n-1?" ":"\n");
}

void solve(){
    int n,m;
    string s,t;cin>>s>>t;
    n=s.size();
    m=t.size();
    vector<vector<long long>> dp(m+1,vector<long long>(n+1,0ll));
    for(int i=0;i<dp[0].size();i++){
        dp[m][i]=1;
        if(i>0){
            dp[m][i]=(dp[m][i-1]*2ll)%MOD;
        }
    }
    for(int j=1;j<=n;j++){
        for(int i=m-1;i>=0;i--){
            if(s[j-1]==t[i]){
                dp[i][j]=(dp[i+1][j-1]+2ll*dp[i][j-1])%MOD;
            }
            else{
                dp[i][j]=2ll*dp[i][j-1]%MOD;
            }
        }
    }
    long long ans=0;
    for(int i=0;i<dp[0].size();i++){
        ans+=dp[0][i];
        ans%=MOD;
    }
    for(int i=0;i<dp.size();i++) print_vec(dp[i]);
    cout<<ans<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}