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

int get_num(long long s,long long e,vector<long long>& d, int n){
    if(e<d[0] || s>d[n-1]) return 0;
    int l=0,r=n-1,mid,x,y;
    while(r-l>1){
        mid=(l+r)/2;
        if(d[mid]<s) l=mid;
        else r=mid;
    }    
    if(d[l]>=s) r=l;
    x=r;
    l=0;r=n-1;
    while(r-l>1){
        mid=(l+r)/2;
        if(d[mid]>e) r=mid;
        else l=mid;
    }
    if(d[r]<=e) l=r;
    y=l;
    return max(0,y-x+1);
}

long long rec(long long s,long long e,int a, int b,vector<long long>& d,int k){
    int num=get_num(s,e-1,d,k);
    if(num==0) return 1ll*a;
    long long ans=1ll*b*num*(e-s);
    if(e-s>1){
        long long dd=(e-s)/2;
        ans=min(rec(s,s+dd,a,b,d,k)+rec(e-dd,e,a,b,d,k),ans);
    }
    return ans;
}

void solve(){
    int n,k,a,b;
    cin>>n>>k>>a>>b;
    vector<long long> x(k,0ll);
    for(int i=0;i<k;i++) cin>>x[i];
    sort(full(x));
    long long ans=rec(1,(1ll<<(1ll*n))+1,a,b,x,k);
    cout<<ans<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}