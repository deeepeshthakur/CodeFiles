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
    int n,m;cin>>n>>m;
    vector<long long> a(max(m,n)+10,0ll);
    a[0]=1;a[1]=2;a[2]=4;
    for(int i=3;i<a.size();i++) a[i]=(a[i-1]+a[i-2])%MOD;
    cout<<(a[n]+a[m]+MOD-2)%MOD<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}