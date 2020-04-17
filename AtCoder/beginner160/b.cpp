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
    long long x,ans=0;
    cin>>x;
    if(x>=500){
        ans+=(x/500)*1000;
        x%=500;
    }

    if(x>=5){
        ans+=(x/5)*5;
        x%=5;
    }
    cout<<ans<<"\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}