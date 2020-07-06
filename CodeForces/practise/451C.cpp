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

long long f1(long long k,long long d1,long long d2){
    if((k-2*d2-d1)%3==0) return (k-2*d2-d1)/3;
    return -1;
}

bool f(long long n,long long k,long long d1,long long d2){
    long long c=f1(k,d1,d2),b=c+d2,a=b+d1;n-=k;
    if(a>=0 && b>=0 && c>=0){
        long long mx=max(a,max(b,c));
        n-=mx-a;
        n-=mx-b;
        n-=mx-c;
        // cout<<n<<" "<<k<<" "<<d1<<" "<<d2<<" "<<a<<" "<<b<<" "<<c<<"\n";
        a=b=c=mx;
        if(n>=0 && n%3==0) return true;
    }
    return false;
}

void solve(){
    long long n,k,d1,d2;
    cin>>n>>k>>d1>>d2;
    if(f(n,k,d1,d2)||f(n,k,d1,-1ll*d2)||f(n,k,-1ll*d1,d2)||f(n,k,-1ll*d1,-1ll*d2)) cout<<"yes\n";
    else cout<<"no\n";
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