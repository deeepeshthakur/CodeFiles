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
    int n;cin>>n;
    vector<int> a(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    if(n==1){
        cout<<"1\n";
        return;
    }
    vector<bool> is_prime(int(1e5)+1,true);
    vector<vector<int>> fac(int(1e5)+1);
    is_prime[0]=false;
    is_prime[1]=false;
    fac[1].pb(1);
    for(int i=2;i<is_prime.size();i++){
        if(is_prime[i]){
            fac[i].pb(i);
            int j=2;
            while(1ll*i*j<is_prime.size()){
                fac[i*j].pb(i);
                is_prime[i*j]=false;
                j++;
            }
        }
    }

    vector<int> dp(int(1e5)+1,0);
    for(int i=n-1;i>=0;i--){
        int x=a[i],len=0;
        for(int j=0;j<fac[x].size();j++){
            for(int k=(x/fac[x][j])+1;1ll*k*fac[x][j]<dp.size();k++){
                // len=max(len,dp[k*fac[x][j]]);
                if(dp[k*fac[x][j]]>0){
                    len=max(len,dp[k*fac[x][j]]);
                    break;
                }
            }
        }
        dp[x]=len+1;
    }
    int ans=0;
    for(int i=2;i<dp.size();i++){
        ans=max(ans,dp[i]);
    }
    cout<<ans<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}