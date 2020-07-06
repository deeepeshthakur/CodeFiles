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
    long long h;
    string s;
    int n,q;
    cin>>h>>s>>q;
    n=s.size();
    vector<vector<long long>> dp(n,vector<long long>(26,0ll));
    vector<long long> fl(26,0ll);
    for(int i=0;i<n;i++){
        dp[i][int(s[i]-'A')]++;
        fl[int(s[i]-'A')]++;
        if(i>0){
            for(int j=0;j<26;j++) dp[i][j]+=dp[i-1][j];
        }
    }    
    for(int i=0;i<q;i++){
        long long r;
        char c;
        int ind;
        cin>>r>>c;
        ind=int(c-'A');
        long long st=0;
        if(r%2==0){
            st=(r/2)%n;
            st=(st*((r-1)%n))%n;
        }
        else{
            st=((r-1)/2)%n;
            st=(st*(r%n))%n;
        }
        long long ans=0;
        // cout<<r<<" "<<st<<"\n";
        r+=st;
        ans-=(st>0?dp[st-1][ind]:0ll);
        ans+=fl[ind]*(r/n);
        r=r%n;
        ans+=(r>0?dp[r-1][ind]:0ll);
        cout<<ans<<"\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}