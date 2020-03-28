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
    long long k;
    cin>>n>>k;
    long long b1=2,b2=1;
    for(long long i=1;i<=n;i++){
        if((i*i-3*i+2)/2<k)
            b1=i;
    }

    for(long long i=1;i<b1;i++){
        if((b1*b1-3ll*b1+2ll*i+2ll)/2<=k){
            b2=i;
        }
    }
    for(long long i=n;i>0;i--){
        if(i!=b1 && i!=b2){
            cout<<'a';
        }
        else{
            cout<<'b';
        }
    }
    cout<<"\n";
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