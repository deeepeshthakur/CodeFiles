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

void apply_choice(int &a, int &b,int &c, char x, char y){
    if(x=='A'){
        a++;
        if(y=='B') b--;
        if(y=='C') c--;
        return;
    }

    if(x=='B'){
        b++;
        if(y=='A') a--;
        if(y=='C') c--;
        return;
    }

    if(x=='C'){
        c++;
        if(y=='B') b--;
        if(y=='A') a--;
        return;
    }
}

void solve(){
    int n;cin>>n;
    int a,b,c;
    cin>>a>>b>>c;
    vector<string> s(n);
    for(int i=0;i<n;i++) cin>>s[i];

    vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(4,-1)));
    for(int i=0;i<n;i++){
        if(i==0){
            int ta=a,tb=b,tc=c;
            apply_choice(ta,tb,tc,s[i][0],s[i][1]);
            dp[0][0]={ta,tb,tc,-1};
            if(min(ta,min(tb,tc))>=0) dp[0][0][3]=0;
            ta=a;tb=b;tc=c;
            apply_choice(ta,tb,tc,s[i][1],s[i][0]);
            dp[0][1]={ta,tb,tc,-1};
            if(min(ta,min(tb,tc))>=0) dp[0][1][3]=0;

        }
        else{
            int ta,tb,tc;
            for(int j=0;j<2;j++){
                if(dp[i-1][0][3]>=0 && dp[i-1][1][3]>=0){
                    ta=dp[i-1][0][0];
                    tb=dp[i-1][0][1];
                    tc=dp[i-1][0][2];
                    int mna=min(ta,min(tb,tc)),mxa=max(ta,max(tb,tc));
                    apply_choice(ta,tb,tc,s[i][j],s[i][1-j]);
                    dp[i][j]={ta,tb,tc,0};
                    ta=dp[i-1][1][0];
                    tb=dp[i-1][1][1];
                    tc=dp[i-1][1][2];
                    apply_choice(ta,tb,tc,s[i][j],s[i][1-j]);
                    int mnb=min(ta,min(tb,tc)),mxb=max(ta,max(tb,tc));
                    if(mnb>mna || (mnb==mna && mxa>mxb)){
                        dp[i][j]={ta,tb,tc,1};
                    }
                }
                else{
                    if(dp[i-1][0][3]>=0 || dp[i-1][1][3]>=0){
                        if(dp[i-1][0][3]>=0){
                            ta=dp[i-1][0][0];
                            tb=dp[i-1][0][1];
                            tc=dp[i-1][0][2];
                            apply_choice(ta,tb,tc,s[i][j],s[i][1-j]);
                            dp[i][j]={ta,tb,tc,0};
                        }
                        else{
                            ta=dp[i-1][1][0];
                            tb=dp[i-1][1][1];
                            tc=dp[i-1][1][2];
                            apply_choice(ta,tb,tc,s[i][j],s[i][1-j]);
                            dp[i][j]={ta,tb,tc,1};
                        }
                    }
                }

                if(min(dp[i][j][0],min(dp[i][j][1],dp[i][j][2]))<0) dp[i][j][3]=-1;
            }
        }
    }

    int prev=-1;
    if(dp[n-1][0][3]>=0) prev=0;
    if(dp[n-1][1][3]>=0) prev=1;
    if(prev==-1){
        cout<<"No\n";
        return;
    }
    cout<<"Yes\n";
    vector<vector<int>> ans(n,vector<int>(3,0));
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<3;j++){
            ans[i][j]=dp[i][prev][j];
        }
        prev=dp[i][prev][3];
    }
    for(int i=0;i<n;i++){
        if(i==0){
            if(ans[i][0]>a) cout<<"A\n";
            if(ans[i][1]>b) cout<<"B\n";
            if(ans[i][2]>c) cout<<"C\n";
        }
        else{
            for(int j=0;j<3;j++){
                if(ans[i][j]>ans[i-1][j]) {cout<<char('A'+j)<<"\n";break;}
            }
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}