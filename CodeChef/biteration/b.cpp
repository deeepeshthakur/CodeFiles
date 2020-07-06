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

int f(int ind,int n,int k,vector<int> a){
    a[0]=a[n-1]=ind;
    vector<int> dp(n,-1),step(n,-1);
    for(int i=0;i<n;i++) dp[i]=(a[i]==ind?i:((i>0)?dp[i-1]:-1));
    // for(int i=0;i<n;i++) cout<<dp[i]<<(i+1<n?" ":"\n");
    step[n-1]=0;
    for(int i=n-2;i>=0;i--)
        if(a[i]==ind){
            int nxt=dp[min(n-1,i+k)];
            if(nxt>i && step[nxt]>=0) step[i]=step[nxt]+1;
        }
    // for(int i=0;i<n;i++) cout<<step[i]<<(i+1<n?" ":"\n");
    return step[0];
}

void solve(){
    int n,k;
    cin>>n>>k;
    n+=2;
    vector<int> a(n,0);
    for(int i=1;i<n-1;i++) cin>>a[i];
    for(int i=0;i<n;i++) a[i]%=2;
    int ans=-1,tmp;
    tmp=f(0,n,k,a);
    ans=(ans!=-1 && tmp!=-1? min(ans,tmp):(tmp+ans+1));
    tmp=f(1,n,k,a);
    ans=(ans!=-1 && tmp!=-1? min(ans,tmp):(tmp+ans+1));
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