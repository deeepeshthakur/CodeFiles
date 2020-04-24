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

long long gm(long long a,long long b){
    if(a!=-1 && b!=-1) return max(a,b);
    return -1;
}

int bs(long long a, int n, vector<long long>& b){
    if(a>b[n-1]) return n+1;
    int l=0,r=n-1,mid;
    while(r-l>1){
        mid=(l+r)/2;
        if(b[mid]<a) l=mid;
        else r=mid;
    }
    if(b[l]>=a) r=l;
    return r;
}

void solve(){
    int m,n,k;
    long long ta,tb;
    cin>>n>>m>>ta>>tb>>k;
    vector<long long> a(n,0ll),b(m,0ll);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    long long ans=b[0]+tb;
    if(a[0]+ta>b[m-1]) ans=-1;
    for(int i=0;i<=k;i++){
        if(i<n){
            int ind=bs(a[i]+ta,m,b)+k-i;
            if(ind<m) ans=gm(ans,b[ind]+tb);
            else ans=-1;
        }
        else ans=-1;
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