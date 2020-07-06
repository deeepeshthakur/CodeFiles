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
    int n,A;
    cin>>n>>A;
    vector<int> c(n,0),dp(int(1e6)+1,0);
    for(int i=0;i<n;i++) cin>>c[i];
    for(int i=0;i<n;i++){
        if(c[i]==A) dp[A]++;
        else{
            if(dp[c[i]]>=dp[A]) dp[c[i]]++;
        }
    }
    for(int i=1;i<dp.size();i++) 
        if(i!=A && dp[i]>=dp[A]){
            cout<<i<<"\n";
            return;
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