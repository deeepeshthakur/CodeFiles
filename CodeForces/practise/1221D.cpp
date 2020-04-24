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

long long gm(long long a, long long b){
    if(a!=-1 && b!=-1) return min(a,b);
    return (a==-1)?b:a;
}

void solve(){
    int n;cin>>n;
    vector<long long> a(n,0ll),b(n,0ll);
    for(int i=0;i<n;i++) cin>>a[i]>>b[i];
    // for(int i=0;i<n;i++) cin>>b[i];

    vector<vector<long long>> dp(n,vector<long long>(5,-1ll));
    for(int i=n-1;i>=0;i--){
        if(i==n-1){
            for(int j=0;j<5;j++) dp[i][j]=b[i]*j;
        }
        else{
            for(int j=0;j<5;j++){
                for(int k=0;k<5;k++){
                    if(a[i]+j!=a[i+1]+k){
                        dp[i][j]=gm(dp[i][j],dp[i+1][k]+b[i]*j);
                    }
                }
            }
        }
    }
    long long ans=-1;
    for(int i=0;i<5;i++)
        ans=gm(ans,dp[0][i]);
    cout<<ans<<"\n";

    // for(int i=0;i<n;i++){
    //     print_vec(dp[i]);
    // }
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