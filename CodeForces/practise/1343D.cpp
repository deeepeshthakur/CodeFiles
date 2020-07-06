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
    int n,k;
    cin>>n>>k;
    vector<int> a(n,0),dp_sm(2*k+1,0),dp_min(k+1,0),dp_max(k+1,0);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;2*i<n-1;i++){
        dp_sm[a[i]+a[n-1-i]]++;
        dp_min[min(a[i],a[n-1-i])]++;
        dp_max[max(a[i],a[n-1-i])]++;
    }
    // print_vec(dp_sm);

    for(int i=1;i<=k;i++) dp_max[i]+=dp_max[i-1];
    for(int i=k-1;i>=0;i--) dp_min[i]+=dp_min[i+1];
    // print_vec(dp_min);
    // print_vec(dp_max);
    int ans=n,x=0;
    for(int i=2;i<dp_sm.size();i++){
        int tmp=(i<dp_min.size()?dp_min[i]:0)+(i-k-1<dp_max.size() && i-k-1>=0 ? dp_max[i-k-1]:0);
        // cout<<i<<" "<<ans<<" "<<tmp<<"\n";
        tmp=(n-2*(dp_sm[i]+tmp))/2 + 2*tmp;
        if(ans>tmp) ans=tmp;
    }
    // cout<<"\n";
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