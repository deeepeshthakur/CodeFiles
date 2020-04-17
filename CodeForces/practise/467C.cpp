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

void print_vec(vector<long long>& a, int n=-1){
    n=(n==-1?a.size():n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<(i<n-1?" ":"\n");
}

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<long long> p(n,0ll),a(n-m+1,0ll);
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    for(int i=1;i<n;i++){
        p[i]+=p[i-1];
    }
    for(int i=0;i<a.size();i++){
        a[i]=p[i+m-1]-(i>0?p[i-1]:0ll);
    }
    // print_vec(a);
    vector<vector<long long>> dp(a.size(),vector<long long>(k+1,0ll));
    for(int j=0;j<=k;j++){
        long long mx=0;
        for(int i=dp.size()-1;i>=0;i--){
            if(j>0){
                if(i+m<dp.size()){
                    mx=max(mx,dp[i+m][j-1]);
                }
                dp[i][j]=a[i]+mx;
            }
            else{
                dp[i][j]=0;
            }
        }
    }
    long long ans=0;
    for(int i=0;i<dp.size();i++){
        ans=max(ans,dp[i][k]);
    }
    cout<<ans<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}