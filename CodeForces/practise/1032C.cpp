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

void solve(){
    int n;cin>>n;
    vector<int> a(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<vector<int>> dp(n,vector<int>(5,-1));
    for(int i=0;i<5;i++) dp[n-1][i]=-2;
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<5;j++){
            if(a[i]<a[i+1]){
                for(int k=j+1;k<5;k++) 
                    if(dp[i+1][k]!=-1) {dp[i][j]=k; k=10;}
            }
            if(a[i]>a[i+1]){
                for(int k=0;k<j;k++)
                    if(dp[i+1][k]!=-1) {dp[i][j]=k;k=10;}
            }
            if(a[i]==a[i+1]){
                for(int k=0;k<5;k++)
                    if(k!=j && dp[i+1][k]!=-1) {dp[i][j]=k;k=10;}
            }
        }
    }
    for(int i=0;i<5;i++){
        if(dp[0][i]!=-1){
            vector<int> ans;
            int ctr=i;
            for(int x=0;x<n && ctr>-1;x++){
                ans.pb(ctr+1);
                ctr=dp[x][ctr];
            }
            for(int x=0;x<ans.size();x++) cout<<ans[x]<<" ";
            cout<<"\n";
            return;
        }
    }
    cout<<"-1\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}