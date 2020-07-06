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

int gm(int a, int m){
    a%=m;
    return (a==0?m:a);
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<long long> a(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) a[i]%=m;
    sort(full(a));
    if(n>m || a[0]==0){
        cout<<"YES\n";
        return;
    }
    vector<vector<bool>> dp(n,vector<bool>(m+1,false));
    dp[0][0]=true;
    dp[0][a[0]]=true;
    for(int i=0;i<n-1;i++)
        for(int j=0;j<=m;j++)
            if(dp[i][j]) dp[i+1][j]=dp[i+1][gm(j+a[i+1],m)]=true;
    if(dp[n-1][m]) cout<<"YES\n";
    else cout<<"NO\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}