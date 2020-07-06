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
    long long a,b,n,m;
    cin>>a>>b>>n>>m;
    long long del=max(a,b)-min(a,b);
    n-=min(n,del);
    del=min(a,b);
    a=del;
    b=del;
    if(n+m<=a+b){
        long long mn=min(n,m);
        m-=mn;
        n-=mn;
        a-=mn;
        b-=mn;
        if(n==0 && m==0){
            cout<<"Yes\n";
            return;
        }

        if(n>0){
            if(n<=b+a){
                cout<<"Yes\n";
                return;
            }
        }
        else{
            if(m<=min(a,b)){
                cout<<"Yes\n";
                return;
            }
        }
    }
    cout<<"No\n";
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