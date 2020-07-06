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
const long long MOD=998244353ll;

void mul(int ind, vector<vector<long long>>& a, vector<long long>& b){
    int n=a.size(),m=b.size();
    for(int i=0;i<a[ind+1].size();i++) a[ind+1][i]=0;
    for(int i=0;i<m;i++)
        for(int j=0;j<a[ind].size();j++)
            if(i+j<a[ind+1].size()){
                a[ind+1][i+j]+=(b[i]*a[ind][j])%MOD;
                a[ind+1][i+j]%=MOD;
            }
}

void solve(){
    string s;
    cin>>s;
    long long k;
    cin>>k;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(i<n-1-i) swap(s[i],s[n-1-i]);
    }
    vector<int> dp(n,0);
    for(int i=0;i<n;i++) dp[i]=(i+1<n && s[i+1]=='1'?1:0) + (i+1<n?dp[i+1]:0);
    vector<vector<long long>> v(n+1,vector<long long>(9001,0));
    v[0][0]=1;
    for(int i=n-1;i>=0;i++)
        if(s[i-1]=='0'){
            vector<long long> v_tmp(dp[i]+1,1ll);
            mul(i-1,v,v_tmp);
        }
        else{
            for(int j=0;j<9001;j++) v[i][j]=v[i-1][j];
        }

    for(int i=0;i<10 && i<n;i++){
        for(int j=0;j<v[i].size() && j<50;j++) cout<<v[i][j]<<" ";
        cout<<"\n";
    }
    long long ans=0,tmp=0;
    for(int i=0;i<n;i++) if(s[i]=='1') tmp++;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k && j<=tmp;j++)
            if(s[i-1]=='0'){
                ans+=v[i][j];
                ans%=MOD;
            }
    }
    cout<<(ans+1)%MOD<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}