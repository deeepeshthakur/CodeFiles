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

inline long long gs(vector<long long>& a, int l,int r){
    return a[r]-(l>0?a[l-1]:0ll);
}

long long f(int x, vector<long long>& v){
    long long ans=0;
    int n=v.size();
    map<long long,int> ht;
    for(int i=0;i<n;i++)
        if(ht.find(v[i])==ht.end()){
            ht[v[i]]=1;
        }
        else ht[v[i]]++;
    for(int i=0;i<n;i++)
        if(ht.find(1ll*x-v[i])!=ht.end()){
            ans+=(ht.find(1ll*x-v[i])!=ht.end()?ht[1ll*x-v[i]]:0ll);
        }
    return ans;
}

void solve(){
    int n,x;
    cin>>n>>x;
    vector<long long> a(n,0ll);
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]+=(i>0?a[i-1]:0);
    } 
    long long ans=0;
    for(int i=1;i<=x;i++){
        if(x%i==0){
            vector<long long> v;
            int curr=x/i,tmp=0,mn,mx;
            for(int j=0;j+i-1<n;j++){
                tmp=gs(a,j,j+i-1);
                if(j==0) mx=mn=tmp;
                mn=min(mn,tmp);
                mx=max(mx,tmp);
            } 
            for(int j=0;j+i-1<n;j++){
                tmp=gs(a,j,j+i-1);
                if(tmp+mn<=curr && curr<=mx+tmp) v.pb(tmp);
            } 
            ans+=f(x/i,v);
        }
    }
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