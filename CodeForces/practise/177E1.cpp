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

long long f(long long c, int n, long long x, vector<pair<long long,long long>>& a){
    c-=n;
    for(int i=0;i<n;i++) c-=(x*a[i].first/a[i].second);
    return c;
}

void solve(){
    int n;
    long long c;
    cin>>n>>c;
    vector<pair<long long,long long>> a(n,{0ll,0ll});
    for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second;
    bool flag=true;
    for(int i=0;i<n;i++) if(a[i].first>0) flag=false;
    if(flag && n==c){
        cout<<"-1\n"; return;
    }
    if(flag && n!=c){
        cout<<"0\n"; return;
    }

    long long l=0,r=MOD*MOD;
    
    flag=true;
    while(flag){
        long long del=1;
        flag=f(c,n,l+del,a)>0;
        while(f(c,n,l+del*2,a)>0) del*=2;
        if(flag) l+=del;
    }
    l++;
    r=l;
    flag=true;
    while(flag){
        long long del=1;
        flag=f(c,n,r+del,a)==0;
        while(f(c,n,r+del*2,a)==0) del*=2;
        if(flag) r+=del;
    }
    long long k=0;
    if(f(c,n,l,a)==0 && f(c,n,r,a)==0) k=r-l+1;
    cout<<k<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}