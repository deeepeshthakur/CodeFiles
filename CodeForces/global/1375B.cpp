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

int gn(int i, int j,int n,int m){
    int ans=0;
    if(i>0) ans++;
    if(j>0) ans++;
    if(i+1<n) ans++;
    if(j+1<m) ans++;
    return ans;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> dp(n,vector<int>(m,0));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>dp[i][j];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) 
        if(dp[i][j]<=gn(i,j,n,m)){
            dp[i][j]=gn(i,j,n,m);
        }
        else{
            cout<<"NO\n";
            return;
        }
    cout<<"YES\n";
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) cout<<dp[i][j]<<" ";
        cout<<"\n";
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