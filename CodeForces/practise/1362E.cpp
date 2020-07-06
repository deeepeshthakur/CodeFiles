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
    int n,p;
    cin>>n>>p;
    vector<int> k(n,0);
    for(int i=0;i<n;i++) cin>>k[i];
    sort(full(k));
    vector<pair<int,int>> dist_k;
    for(int i=0;i<n;i++)
        if(dist_k.size()>0 && dist_k.back().first==k[i]){
            dist_k.back().second++;
        }
        else{
            dist_k.pb({k[i],1});
        }

    if(p==1){
        cout<<n%2<<"\n";
    }
    else{
        sort(rfull(dist_k));
        
    }
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