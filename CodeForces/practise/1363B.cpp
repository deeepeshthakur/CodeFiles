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

int f(int n,string s, char c){
    vector<int> dp(n,0);
    for(int i=0;i<n;i++) dp[i]=(s[i]==c?1:0)+(i>0?dp[i-1]:0);
    int ans=n+10;
    for(int i=0;i<n;i++){
        ans=min(ans,i+1-dp[i]+dp[n-1]-dp[i]);
    }
    return ans;
}

void solve(){
    string s;
    cin>>s;
    int n=s.size();
    cout<<min(f(n,s,'0'),f(n,s,'1'))<<"\n";
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