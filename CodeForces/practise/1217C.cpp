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
    string s;
    cin>>s;
    vector<int> a(s.size(),0);
    for(int i=0;i<a.size();i++) a[i]=(s[i]=='1'?1:0);
    int n=a.size();
    vector<int> dp(n,0);
    for(int i=0;i<n;i++){
        if(i>0){
            if(a[i-1]==1) dp[i]=0;
            else dp[i]=dp[i-1]+1;
        }
    }

    long long ans=0;
    for(int i=0;i<n;i++){
        if(a[i]==1){
            int curr=0;
            for(int j=1;j<20 && i+j-1<n;j++){
                curr=curr*2+a[i+j-1];
                if(j+dp[i]>=curr) ans++;
            }
        }
    }
    cout<<ans<<"\n";
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