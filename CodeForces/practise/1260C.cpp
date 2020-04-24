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
vector<bool> ans;
void solve(){
   long long a,r,b,k;cin>>r>>b>>k;
   if(r>b) swap(r,b);
   a=__gcd(b,r);
   long long c=b/a,d=r/a;
   if(k>(b-1-a)/r+1) ans.pb(true);
   else ans.pb(false);
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        solve();
    }
    for(int i=0;i<ans.size();i++) 
        if(ans[i]) cout<<"OBEY\n";
        else cout<<"REBEL\n";
    return 0;
}