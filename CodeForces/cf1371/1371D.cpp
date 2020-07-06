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
    vector<vector<int>> dp(n,vector<int>(n,0));
    int m=k/n,lim=k%n;
    for(int i=0;i<n;i++){
        int num=m+(lim>0?1:0);
        lim=max(0,lim-1);
        for(int j=0;j<num;j++){
            dp[i][(j+i)%n]=1;
        }
    }
    if(k%n==0){
        cout<<0<<"\n";
    }
    else cout<<2<<"\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j];
        }
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