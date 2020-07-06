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

long long pow_mod(long long a, long long b, long long mod){
    long long ans=1;
    a%=mod;
    while(b>0){
        if(b&1){
            ans*=a;
            ans%=mod;
        }
        b=b>>1;
        a=(a*a)%mod;
    }
    return ans;
}

void solve(){
    long long a,b;
    long long n;
    cin>>a>>b>>n;
    vector<long long> pf;
    for(long long i=1;i*i<=b;i++){
        if(b%i==0){
            if(i<b/i){
                if(i!=1)pf.pb(i);
                pf.pb(b/i);
            }
            if(i!=1 && i*i==b) pf.pb(i);
        }
    }

    long long currmin=b,currd,currc;
    for(int i=0;i<pf.size();i++){
        long long bdash=b/pf[i],m=0,del;
        while(a-(m+1)*bdash>0) m++;
        del=a-m*bdash;
        if(del<currmin){
            currd=b/bdash;
            currc=m;
        }
    }
    long long gd=__gcd(currc,currd);
    currd/=gd;
    currc/=gd;
    cout<<currc<<" "<<currd<<endl;

    long long m2=1,cc,dd;
    for(int i=0;i<pf.size();i++){
        long long dmd=pow_mod(a%b,b-2,b);
        long long bdash=b/pf[i];
        if(dmd%bdash!=0){
            long long md=pf[i]*dmd,mul=b*pf[i];
            long long l=0,r=n/mul,mid;
            while(r-l>1){
                mid=(l+r)/2;
                if(mid*mul+md<=n){
                    l=mid;
                }
                else r=mid;
            }
            if(r*mul+md<=n) l=r;
            if(m2<=(l*mul+md)/pf[i]){
                m2=(l*mul+md)/pf[i];
                dd=m2*pf[i];
                l=1,r=dd;
                while(r-l>1){
                    if((1.0*mid*b)/(1.0*dd*a)<1) l=mid;
                    else r=mid;
                }
                if((1.0*r*b)/(1.0*dd*a)<1) l=r;
                cc=l;
            }
        }
    }

    long long tm=__gcd(cc,dd);
    cc/=tm;
    dd/=tm;
    if((1.0*currc*dd)/(1.0*currd*cc)<1){
        currd=dd;
        currc=cc;
    }
    cout<<currc<<" "<<currd<<"\n";
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