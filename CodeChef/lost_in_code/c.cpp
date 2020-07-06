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
    cin>>a>>b;
    vector<bool> c(26,true);
    for(int i=0;i<b.size();i++) c[int(b[i]-'A')]=false;
    string ans="";
    for(int i=0;i<a.size();i++) if(c[int(a[i]-'A')]) ans.pb(a[i]);
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