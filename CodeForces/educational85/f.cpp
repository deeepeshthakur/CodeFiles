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
long long MD=1e9+7;
long long mul=1e6;

long long dp_fun(unordered_map<long long,long long>& dp,int i, int j, vector<int>& a, vector<int>& b, vector<long long>& p, vector<long long>& psum){
    if(i<j){
        return MD;
    }
    if(i<0 && j<0){
        return 0ll;
    }
    if(i>=0 && j<0){
        return psum[i];
    }
    if(dp.find(i*mul+j)==dp.end()){
        long long ans=0;
        if(a[i]>b[j]) ans=dp_fun(dp,i-1,j,a,b,p,psum)+p[i];
        if(a[i]==b[j]) ans=min(dp_fun(dp,i-1,j-1,a,b,p,psum),dp_fun(dp,i-1,j,a,b,p,psum)+min(0ll,p[i]));
        if(a[i]<b[j]) ans=dp_fun(dp,i-1,j,a,b,p,psum)+min(0ll,p[i]);
        dp.insert({i*mul+j,ans});
    }
    return (dp.find(i*mul+j))->second;
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<long long> p(n),psum(n,0ll);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>p[i];
        psum[i]=p[i];
        if(i>0){
            psum[i]+=psum[i-1];
        }
    }

    int m;
    cin>>m;
    vector<int> b(m);
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    long long ans=0,sm=0;
    for(int i=0;i<n;i++){
        ans+=abs(p[i]);
        if(p[i]>0)
            sm+=p[i];
    }
    ans=2ll*(ans+100);
    MD=max(ans,MD);
    unordered_map<long long,long long> dp;
    ans=dp_fun(dp,n-1,m-1,a,b,p,psum);
    if(ans>sm){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n"<<ans<<"\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}