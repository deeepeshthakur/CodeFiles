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
    int n,ln=int(1e7);
    cin>>n;
    ln=n;
    vector<bool> primes(ln+100,true);
    vector<vector<int>> dp(ln+100);
    primes[0]=primes[1]=false;
    for(int i=0;i<primes.size();i++)
        if(primes[i]){
            dp[i].pb(i);
            int j=2;
            while(1ll*i*j<primes.size()){
                primes[i*j]=false;
                dp[i*j].pb(i);
                j++;
            }
        }
    long long ans=1;
    for(int i=2;i<=n;i++){
        int k=1,num=i;
        for(int j=0;j<dp[i].size();j++){
            int cnt=0;
            while(num%dp[i][j]==0){
                num/=dp[i][j];
                cnt++;
            }
            k*=(cnt+1);
        }
        ans+=(1ll*k*i);
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