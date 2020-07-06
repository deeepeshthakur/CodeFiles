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
    long long n,m;cin>>m>>n;
    long double ans=0;
    for(int i=1;i<m;i++){
        ans+=pow((1.0*i/m),1.0*n);
    }
    ans=1.0*m-ans;
    cout<<fixed<<setprecision(12)<<ans<<'\n';
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}