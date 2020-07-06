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

void print_vec(vector<int>& a, int n=-1){
    n=(n==-1?a.size():n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<(i<n-1?" ":"\n");
}

int f(int n, vector<pair<int,int>>& a){
    int mx_thickness=0,mx_weight=0;
    for(int i=0;i<n;i++) {mx_thickness+=a[i].first; mx_weight+=a[i].second;}
    vector<vector<int>> dp(n+1,vector<int>(mx_thickness+10,-1));
    dp[0][0]=mx_weight;
    for(int i=0;i<n;i++)
        for(int j=0;j<dp[i].size();j++)
            if(dp[i][j]!=-1){
                if(dp[i+1][j]==-1) dp[i+1][j]=mx_weight;
                dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
                if(j+a[i].first<dp[i+1].size()){
                    if(dp[i+1][j+a[i].first]==-1) dp[i+1][j+a[i].first]=mx_weight;
                    dp[i+1][j+a[i].first]=min(dp[i+1][j+a[i].first],max(0,dp[i][j]-a[i].second));
                }
            }
    

    int ans=mx_thickness;
    for(int i=0;i<dp.size();i++) for(int j=0;j<dp[i].size();j++) if(dp[i][j]!=-1 && dp[i][j]<=j) ans=min(ans,j);
    return ans;
}

void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> a(n,{0,0});
    for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second;
    cout<<f(n,a)<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}