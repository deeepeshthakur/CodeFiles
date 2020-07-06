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
    int n;
    cin>>n;
    int l=1,r=n,mid;
    while(r-l>1){
        int mid=(r+l)/2;
        if(mid<=n && 2*mid<=n) l=mid;
        else r=mid;
    }
    if(2*r<=n) l=r;
    cout<<l<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}