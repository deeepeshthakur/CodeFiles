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
const long long MOD=1e9;

bool query(map<pair<long long,long long>,int>& ht, long long x,long long y){
    if(ht.find({x,y})==ht.end()){
        cout<<x<<" "<<y<<endl;
        string s;
        int tmp=0;
        cin>>s;
        if(s[0]!='H'){
            tmp=1;
        }
        if(s[0]=='C')
            tmp=2;
        ht[{x,y}]=tmp;
        return tmp==2 || ht.size()>300;
    }
    return false;
}

void solve(int test_case,long long a,long long b){
    map<pair<long long,long long>,int> ht;
    long long ll=-MOD,rr=MOD;
    long long l=ll,r=0,mid;
    while(r-l>1){
        mid=(l+r)/2;
        if(query(ht,mid,0ll)) return;
        if(ht[{mid,0ll}]==1) r=mid;
        else l=mid;
    }
    if(query(ht,l,0)) return;
    if(ht[{l,0}]==1) r=l;
    ll=r;
    l=0,r=MOD;
    while(r-l>1){
        mid=(l+r)/2;
        if(query(ht,mid,0ll)) return;
        if(ht[{mid,0}]==1) l=mid;
        else r=mid;
    }
    if(query(ht,r,0)) return;
    if(ht[{r,0}]==1) l=r;
    rr=l;
    l=ll;r=rr;
    if(ll>-MOD) l=ll-1;
    if(rr<MOD) r=rr+1;
    long long xi=(l+rr)/2,xl=(ll+r)/2;
    for(int x=xi;x<=xl;x++){
        ll=-MOD;rr=MOD;
        l=0;r=MOD;
        while(r-l>1){
            mid=(l+r)/2;
            if(query(ht,x,mid)) return;
            if(ht[{x,mid}]==1) l=mid;
            else r=mid;
        }
        if(query(ht,x,r)) return;
        if(ht[{x,r}]==1) l=r;
        rr=l;
        l=-MOD,r=0;
        while(r-l>1){
            mid=(l+r)/2;
            if(query(ht,x,mid)) return;
            if(ht[{x,mid}]==1) r=mid;
            else l=mid;
        }
        if(query(ht,x,l)) return;
        if(ht[{x,l}]==1) r=l;
        ll=r;
        if(query(ht,x,(ll+rr)/2)) return;
    }
    while(!query(ht,l=0,l++))
    return;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t;
    cin >> t;
    long long a,b;
    cin>>a>>b;
    for(int i=1;i<=t;i++){
        solve(i,a,b);
    }
    return 0;
}