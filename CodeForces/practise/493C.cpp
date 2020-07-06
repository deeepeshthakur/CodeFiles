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

int gs(long long d, vector<long long>& a){
    if(d<a[0]) return a.size()*3;
    int n=a.size(),l=0,r=n-1,mid;
    while(r-l>1){
        mid=(l+r)/2;
        if(a[mid]>d) r=mid;
        else l=mid;
    }
    if(a[r]<=d) l=r;
    return (l+1)*2+(n-1-l)*3;
}

void solve(){
    int n;cin>>n;
    vector<long long> a(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    int m;cin>>m;
    vector<long long> b(m,0);
    for(int i=0;i<m;i++) cin>>b[i];

    sort(full(a));
    sort(full(b));
    int mx_d=3*n-3*m,mx_a=3*n,sc_a,sc_b;
    long long d=0;

    d=a[0]-1;
    sc_a=3*n;
    sc_b=gs(d,b);
    mx_d=sc_a-sc_b;
    mx_a=sc_a;

    for(int i=0;i<n;i++){
        if(i+1>=n || a[i]!=a[i+1]){
            sc_a=(i+1)*2+(n-i-1)*3;
            sc_b=gs(a[i],b);
            if(sc_a-sc_b>mx_d || (sc_a-sc_b==mx_d && mx_a<sc_a)){
                mx_d=sc_a-sc_b;
                mx_a=sc_a;
                d=a[i];
            }
        }
    }

    for(int i=0;i<m;i++){
        if(i+1>=m || b[i]!=b[i+1]){
            sc_b=(i+1)*2+3*(m-i-1);
            sc_a=gs(b[i],a);
            if(sc_a-sc_b>mx_d || (sc_a-sc_b==mx_d && mx_a<sc_a)){
                mx_d=sc_a-sc_b;
                mx_a=sc_a;
                d=b[i];
            }
        }
    }
    if(mx_d<2*n-2*m){
        mx_d=2*n-2*m;
        mx_a=2*n;
        d=max(a[n-1],b[m-1]);
    }
    cout<<mx_a<<":"<<mx_a-mx_d<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}