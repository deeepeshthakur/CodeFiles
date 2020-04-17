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
    int k,ctr=0;
    cin>>k;
    vector<vector<vector<long long>>> dp(10,vector<vector<long long>>(20));
    for(int i=0;i<10;i++){
        dp[i][1].pb(i);
        if(i>0)
            ctr++;
    }

    int dig=2;
    long long mul=10;
    while(ctr<k){
        for(int i=0;i<10;i++){
            for(int j=0;j<dp[i][dig-1].size();j++){
                dp[i][dig].pb(i*mul+dp[i][dig-1][j]);
            }
            if(i>0){
                for(int j=0;j<dp[i-1][dig-1].size();j++){
                    dp[i][dig].pb(i*mul+dp[i-1][dig-1][j]);
                }
            }
            if(i<9){
                for(int j=0;j<dp[i+1][dig-1].size();j++){
                    dp[i][dig].pb(i*mul+dp[i+1][dig-1][j]);
                }
            }
        }
        for(int i=1;i<10;i++){
            ctr+=dp[i][dig].size();
        }
        mul*=10ll;
        dig++;
    }
    vector<long long> ans;
    for(int i=1;i<10;i++){
        for(int j=1;j<dp[i].size();j++){
            for(int k=0;k<dp[i][j].size();k++){
                ans.pb(dp[i][j][k]);
            }
        }
    }
    sort(full(ans));
    cout<<ans[k-1]<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}