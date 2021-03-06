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
    long long n,x,m;
    cin>>n>>x>>m;
    int l=x,r=x;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        if(!(b<l || a>r)){
            l=min(a,l);
            r=max(r,b);
        }
    }
    cout<<r-l+1<<"\n";
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