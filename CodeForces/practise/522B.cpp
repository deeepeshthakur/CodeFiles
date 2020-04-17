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
    int n,sm=0;cin>>n;
    vector<int> w(n,0),hi(n,0),h(n,0);
    for(int i=0;i<n;i++){
        cin>>w[i]>>h[i];
        hi[i]=h[i];sm+=w[i];
    }
    sort(rfull(h));
    for(int i=0;i<n;i++){
        cout<<1ll*(sm-w[i])*(hi[i]==h[0]?h[1]:h[0])<<" ";
    }
    cout<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}