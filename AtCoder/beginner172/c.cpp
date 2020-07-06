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

bool tf(int ln, int n,int m, vector<long long>& a, vector<long long>& b, long long k){
    for(int i=ln;i>=0;i--)
        if(i<=m && (ln-i)<=n)
            if((i-1>=0?b[i-1]:0ll)+(ln-i-1>=0?a[ln-i-1]:0ll)<=k) return true;
    return false;
}

void solve(){
    int n,m;
    long long k;
    cin>>n>>m>>k;
    vector<long long> a(n,0),b(m,0);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    int l=0,r=m+n,mid;
    for(int i=0;i<n;i++) a[i]+=(i>0?a[i-1]:0ll);
    for(int i=0;i<m;i++) b[i]+=(i>0?b[i-1]:0ll);
    while(r-l>1){
        mid=(r+l)/2;
        if(tf(mid,n,m,a,b,k)) l=mid;
        else r=mid;
    }
    if(tf(r,n,m,a,b,k)) l=r;
    cout<<l<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}