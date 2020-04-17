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
    int k,z=262143,y=131072;
    cin>>k;
    vector<vector<int>> dp(3,vector<int>(3,k));
    dp[0][0]=z;
    dp[1][1]=z;
    dp[0][2]=0;
    dp[1][0]=y;
    cout<<3<<" "<<3<<"\n";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}