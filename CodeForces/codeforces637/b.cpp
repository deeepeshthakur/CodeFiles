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

void print_vec(vector<int>& a, int n=-1){
    n=(n==-1?a.size():n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<(i<n-1?" ":"\n");
}

void solve(){
    int n,k;cin>>n>>k;
    vector<long long> a(n,0ll);
    for(int i=0;i<n;i++) cin>>a[i];

    vector<int> dp(n,0ll),dp2(n,0ll);
    for(int i=0;i<n;i++){
        if(i>0 && i+1<n && a[i-1]<a[i] && a[i]>a[i+1]){
            dp2[i]=dp[i]=1;
        }
        if(i>0){
            dp2[i]+=dp2[i-1];
        }
    }

    int ans=0,mx=-1;
    for(int i=0;i<n && i+k-1<n;i++){
        int tmp=dp2[i+k-1]-(i>0?dp2[i-1]:0)-dp[i]-dp[i+k-1];
        if(tmp>mx){
            mx=tmp;
            ans=i;
        }
    }
    cout<<mx+1<<" "<<ans+1<<"\n";
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