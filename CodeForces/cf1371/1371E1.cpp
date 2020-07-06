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

long long ncr(int n, int r, long long mod, vector<long long>& fct){
    if(n<r || r<0 || n<0) return 0ll;
    return (fct[n]*pow_mod(fct[n-r]*fct[r],mod-2,mod))%mod;
}

long long f(long long x, long long p, int n, vector<int>& b, vector<long long>& fct){
    vector<pair<int,int>> tmp;
    for(int i=1;i<b.size();i++)
        if(b[i]>0) tmp.pb({i,b[i]});
    int curr_pos=0, curr = b[0];
    long long sm=1;
    for(int i=0;i<tmp.size() && sm!=0 ;i++){
        // cout<<tmp[i].first<< " " << tmp[i].second << "-----------\n";
        int del=tmp[i].first-curr_pos;
        sm*=(ncr(curr,del,p,fct)*fct[del])%p;
        sm%=p;
        curr-=del;
        curr+=tmp[i].second;
        curr_pos=tmp[i].first;
        // cout<< x << " " << curr << " " << i << " " << sm << "\n";
    }
    if(curr>0) sm*=fct[curr];
    sm%=p;
    return sm;
}

void solve(){
    int n,p;
    cin>>n>>p;
    vector<int> a(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<long long> fct(200000,1ll);
    for(int i=2;i<fct.size();i++) fct[i]=(fct[i-1]*i)%p;
    vector<int> v;
    for(int i=1;i<=2000;i++){
        vector<int> b(2001,0);
        for(int j=0;j<n;j++) b[max(0,a[j]-i)]++;
        if(f(i*1ll,p*1ll,n,b,fct)!=0) v.pb(i);
    }
    cout<<v.size()<<"\n";
    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
    cout<<"\n";
}   

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}