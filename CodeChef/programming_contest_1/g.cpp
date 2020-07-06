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
const long long MOD=998244353ll;

vector<vector<long long>> mul(vector<vector<long long>> a,vector<vector<long long>> b){
    vector<vector<long long>> ans(2,vector<long long>(2,0ll));
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            for(int k=0;k<2;k++)
                ans[i][j]=(ans[i][j]+(a[i][k]*b[k][j])%MOD)%MOD;
    return ans;
}

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

vector<vector<long long>> pow_mod(vector<vector<long long>> a, long long b){
    if(b==0) return vector<vector<long long>>{{1ll,0ll},{0ll,1ll}};
    for(int i=0;i<2;i++) for(int j=0;j<2;j++) a[i][j]%=MOD;
    if(b==1) return a;
    auto x=pow_mod(a,b/2);
    x=mul(x,x);
    if(b%2==1) x=mul(x,a);
    return x;
}

void solve(){
    unsigned long long n,c,d;
    long long a,b,e,f;
    cin>>n>>a>>b>>c>>d>>e>>f;
    long long ans=0,t1,t2;
    if(n>=2){
        auto x=pow_mod(vector<vector<long long>>{{e%MOD,f%MOD},{1ll,0ll}},(n-1)%(MOD-1));
        t1=((x[0][0]*b)%MOD+(x[0][1]*a)%MOD)%MOD;
    }
    else{
        if(n==1) t1=b%MOD;
        else t1=a%MOD;
    }

    vector<unsigned long long> y{c%MOD,d%MOD,(c^d)%MOD};
    t2=y[n%3];
    t1%=MOD;
    t2%=MOD;
    ans=((t1*t2)%MOD+t1+MOD-t2)%MOD;
    cout<<ans<<"\n";
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