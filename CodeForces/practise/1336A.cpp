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
    long long a,b;
    cin>>a>>b;
    long long l=0,r=min(a,b),mid;
    while(r-l>1){
        mid=(r+l)/2;
        if(mid<=a && 2*mid-b<=a-mid) l=mid;
        else r=mid;
    }
    if(r<=a && 2*r-b<=a-r) l=r;
    cout<<l<<"\n";
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