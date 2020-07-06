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

long long f1(int l,int r, vector<long long>& dp){
    return dp[r]-(l>0?dp[l-1]:0ll);
}

bool f(int ind,vector<long long>& dp, int n){

    for(int i=0;i+ind-1<n;i++)
        if(f1(i,i+ind-1,dp)<=0) return false;
    return true;
}

void solve(){
    int n;
    cin>>n;
    vector<long long> a(n,0);
    for(int i=0;i<(n/2)+n%2;i++) cin>>a[i];
    long long x; cin>>x;
    for(int i=n/2+n%2;i<n;i++) a[i]=x;
    
    vector<long long> dp(a.size(),0);
    for(int i=0;i<dp.size();i++) dp[i]=a[i]+(i>0?dp[i-1]:0ll);
    vector<vector<int>> gr(n+1);
    for(int i=1;i<=n;i++){
        gr[i*(n/i)].pb(i);
    }
    vector<bool> vis(n+1,true);
    int ans=-1;
    for(int i=n;i>0 && ans==-1;i--){
        if(vis[i]){
            if(f(i,dp,n)) ans=i;
            else{
                for(int j=0;j<gr[i].size();j++) vis[gr[i][j]]=false;
            }
        }
    }
    cout<<ans<<'\n';
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}