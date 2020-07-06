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
    string a,b;
    cin>>b;
    int n=b.size();
    a.pb(b[0]);
    for(int i=1;i<n;i+=2){
        a.pb(b[i]);
    }
    // a.pb(b.back());
    cout<<a<<"\n";
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