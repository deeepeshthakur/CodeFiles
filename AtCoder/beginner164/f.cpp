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

int gf(int n,vector<vector<int>>& dp, int r,int c, bool which){
    unsigned long long ans;
    if(which){
        if(r!=-1){
            ans=dp[r][0];
            for(int i=0;i<n;i++) ans=(ans&dp[r][i]);
        }
        else{
            ans=dp[0][c];
            for(int i=0;i<n;i++) ans=(ans&dp[i][c]);
        }
    }
    else{
        if(r!=-1){
            ans=dp[r][0];
            for(int i=0;i<n;i++) ans=(ans|dp[r][i]);
        }
        else{
            ans=dp[0][c];
            for(int i=0;i<n;i++) ans=(ans|dp[i][c]);
        }
    }
    return ans;
}

bool get_ans(int n,vector<vector<int>>& dp, vector<int>& s, vector<int>& t,vector<int>& u,vector<int>& v){
    bool flag=true;
    for(int i=0;i<n;i++){
        if(s[i]==0 && u[i]==1){
            for(int j=0;j<n;j++) dp[i][j]=1;
        }
        if(s[i]==1 && u[i]==0){
            for(int j=0;j<n;j++) dp[i][j]=0;
        }
    }

    for(int i=0;i<n;i++){
        if(t[i]==0 && v[i]==1){
            for(int j=0;j<n;j++) dp[j][i]=1;
        }
        if(t[i]==1 && v[i]==0){
            for(int j=0;j<n;j++) dp[j][i]=0;
        }
    }

    bool f2=true;
    for(int i=0;i<n;i++){
        if(s[i]==1 && u[i]==1 && gf(n,dp,i,-1,false)!=1){
            if(f2){
                for(int j=0;j<n;j++){
                    if((t[j]==0 && v[j]==0)||(t[j]==1 && v[j]==1)){
                        f2=(!f2);
                        dp[i][j]=1;
                        j=n+1;
                    }
                }
            }
            else{
                for(int j=n-1;j>=0;j--){
                    if((t[j]==0 && v[j]==0)||(t[j]==1 && v[j]==1)){
                        f2=(!f2);
                        dp[i][j]=1;
                        j=-1;
                    }
                }
            }
        }
    }

    f2=true;
    for(int i=0;i<n;i++){
        if(t[i]==1 && v[i]==1 && gf(n,dp,-1,i,false)!=1){
            if(f2){
                for(int j=0;j<n;j++){
                    if((s[j]==0 && u[j]==0)||(s[j]==1 && u[j]==1)){
                        f2=(!f2);
                        dp[j][i]=1;
                        j=n+1;
                    }
                }
            }
            else{
                for(int j=n-1;j>=0;j--){
                    if((s[j]==0 && u[j]==0)||(s[j]==1 && u[j]==1)){
                        f2=(!f2);
                        dp[j][i]=1;
                        j=-1;
                    }
                }
            }
        }
    }

    flag=true;
    for(int i=0;i<n&&flag;i++){
        if(s[i]==0){
            flag=(flag&&(gf(n,dp,i,-1,true)==u[i]));
        }
        else{
            flag=(flag&&(gf(n,dp,i,-1,false)==u[i]));
        }
        if(t[i]==0){
            flag=(flag&&(gf(n,dp,-1,i,true)==v[i]));
        }
        else{
            flag=(flag&&(gf(n,dp,-1,i,false)==v[i]));
        }
    }
    return flag;
}

void solve(){
    int n;cin>>n;
    vector<int> s(n,0),t(n,0),u1(n,0),v1(n,0);
    vector<unsigned long long> u(n),v(n);
    for(int i=0;i<n;i++) cin>>s[i];
    for(int i=0;i<n;i++) cin>>t[i];
    for(int i=0;i<n;i++) cin>>u[i];
    for(int i=0;i<n;i++) cin>>v[i];
    
    vector<vector<unsigned long long>> dp(n,vector<unsigned long long>(n));
    vector<vector<int>> tmp(n,vector<int>(n,0));
    unsigned long long o=1;
    bool flag=true;
    for(int k=0;k<64 && flag;k++){
        for(int i=0;i<n;i++){
            u1[i]=u[i]%2;
            v1[i]=v[i]%2;
            v[i]/=2;
            u[i]/=2;
            for(int j=0;j<n;j++) tmp[i][j]=0;
        }
        flag=get_ans(n,tmp,s,t,u1,v1);
        if(flag){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(tmp[i][j]==1)
                        dp[i][j]+=(o<<(k*o));
                }
            }
        }
    }

    if(!flag){
        cout<<"-1\n";
        return;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
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