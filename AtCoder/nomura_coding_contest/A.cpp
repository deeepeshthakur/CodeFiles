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
    int h1,m1,h2,m2,k;
    cin>>h1>>m1>>h2>>m2>>k;
    int del=(h2-h1)*60+(m2-m1);
    cout<<max(0,del-k)<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}