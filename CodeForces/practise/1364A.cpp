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
    int n,x;
    cin>>n>>x;
    vector<int> a(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) a[i]%=x;
    int sm=0;
    for(int i=0;i<n;i++) sm=(sm+a[i])%x;
    if(sm!=0){
        cout<<n<<"\n";
        return;
    }
    int l=0,r=n-1;
    for(int i=0;i<n && a[i]==0;i++) l=i+1;
    for(int i=n-1;i>=0 && a[i]==0;i--) r=i-1;
    if(r==-1){
        cout<<"-1"<<"\n";
    }
    else{
        cout<<max(n-l-1,r)<<"\n";
    }
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