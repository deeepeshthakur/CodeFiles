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

long long f(long long a,long long b){
    long long c;
    if(b%a==0) c=b/a;
    else return -1;
    int ctr=0;
    while(c%2==0){
        ctr++;
        c/=2;
    }
    if(c!=1) return -1;
    int ans=0;
    while(ctr>=3){
        ans++;
        ctr-=3;
    }

    while(ctr>=2){
        ans++;
        ctr-=2;
    }

    return ans+ctr;
}

void solve(){
    long long a,b;
    cin>>a>>b;
    if(a>b) swap(a,b);
    cout<<f(a,b)<<"\n";
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