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
    long long n,k;cin>>n>>k;
    long long a,b;
    cin>>a>>b;
    long long ansmx=0,ansmn=MOD*MOD;
    long long s=a+1;
    for(long long i=1;i<=n;i++){
        long long x=(i*k+1-b>s?i*k+1-b-s:-1),y=i*k+1+b-s;
        if(x>0) ansmn=min(ansmn,n*k/__gcd(n*k,x));
        if(x>0) ansmx=max(ansmx,n*k/__gcd(n*k,x));
        if(y>0) ansmn=min(ansmn,n*k/__gcd(n*k,y));
        if(y>0) ansmx=max(ansmx,n*k/__gcd(n*k,y));
    }
    s=k+1-a;
    for(long long i=2;i<=n+1;i++){
        long long x=(i*k+1-b>s?i*k+1-b-s:-1),y=i*k+1+b-s;
        if(x>0) ansmn=min(ansmn,n*k/__gcd(n*k,x));
        if(x>0) ansmx=max(ansmx,n*k/__gcd(n*k,x));
        if(y>0) ansmn=min(ansmn,n*k/__gcd(n*k,y));
        if(y>0) ansmx=max(ansmx,n*k/__gcd(n*k,y));
    }
    cout<<ansmn<<" "<<ansmx<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}