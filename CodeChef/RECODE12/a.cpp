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

int gm(vector<int>& a){
    int n=a.size();
    vector<int> dp(n,0);
    for(int i=n-1;i>=0;i--){
        if(i+1<n){
            if(a[i]+1==a[i+1]){
                if(i+2<n){
                    dp[i]=1+dp[i+2];
                }
                else{
                    dp[i]=1;
                }
            }
            else{
                dp[i]=dp[i+1]+1;
            }
        }
        else{
            dp[i]=1;
        }

        if(i+1<n){
            dp[i]=max(dp[i],dp[i+1]);
        }
    }
    return dp[0];
}

void solve(){
    int n;cin>>n;
    vector<int> a(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];    
    }


    vector<vector<int>> ctr(1001);
    for(int i=0;i<n;i++) ctr[a[i]].pb(i);
    int mx=-1,ind=-1;
    for(int i=1;i<ctr.size();i++){
        if(ctr[i].size()>0){
            int tmp=gm(ctr[i]);
            if(tmp>mx){
                mx=tmp;
                ind=i;
            }
        }
    }
    cout<<ind<<"\n";
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