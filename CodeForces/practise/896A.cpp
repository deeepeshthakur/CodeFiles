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

char rec(int n,vector<long long>& dp, long long k, string& s, string& s1, string& s2, string& s3){
    // cout<<n<<" "<<k<<"\n";
    if(n==0){
        return s[k-1];
    }
    if(dp[n]==-1)
        if(k<=s1.size()) return s1[k-1];
        else
            if(dp[n-1]==-1 || s1.size()+dp[n-1]>=k) return rec(n-1,dp,k-s1.size(),s,s1,s2,s3);
            else{
                k-=(s1.size()+dp[n-1]);
                if(k<=s2.size()) return s2[k-1];
                else{
                    k-=s2.size();
                    if(k<=dp[n-1]) return rec(n-1,dp,k,s,s1,s2,s3);
                    else return s3[k-dp[n-1]-1];
                }
            }

    if(k<=s1.size()) return s1[k-1];
    k-=s1.size();
    if(k<=dp[n-1]) return rec(n-1,dp,k,s,s1,s2,s3);
    k-=dp[n-1];
    if(k<=s2.size()) return s2[k-1];
    k-=s2.size();
    if(k<=dp[n-1]) return rec(n-1,dp,k,s,s1,s2,s3);
    k-=dp[n-1];
    return s3[k-1];
}

void solve(){
    int n;
    long long k;
    cin>>n>>k;
    string s="What are you doing at the end of the world? Are you busy? Will you save us?",s1="What are you doing while sending \"",s2="\"? Are you busy? Will you send \"",s3="\"?";
    // cout<<s[68]<<"\n";

    long long d1=s.size(),d2=s1.size()+s2.size()+s3.size();
    vector<long long> dp(n+1,-1ll);
    dp[0]=d1;
    for(int i=1;i<=n && dp[i-1]<=k;i++) dp[i]=dp[i-1]*2ll+d2;
    if(dp[n]>=0 && dp[n]<k){
        cout<<".";
        return;
    }
    // print_vec(dp);
    cout<<rec(n,dp,k,s,s1,s2,s3);
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
    cout<<"\n";
    return 0;
}