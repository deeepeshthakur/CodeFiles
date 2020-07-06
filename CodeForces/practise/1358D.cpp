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

inline long long f(long long a){
    return (a*a+a)/2;
}

inline long long f2(int x,int y, vector<long long>&a){
    return a[y]-(x>0?a[x-1]:0ll);
}

long long f1(int ind, long long x,vector<long long>& a, vector<long long>& b, vector<long long>& c){
    long long l=0,r=ind,mid,ans=0;
    while(r-l>1){
        mid=(l+r)/2;
        if(f2(mid,ind,c)<=x) r=mid;
        else l=mid;
    }
    if(f2(l,ind,c)<=x) r=l;
    mid=r;
    if(f2(r,ind,c)<=x){
        ans+=f2(r,ind,b);
        x-=f2(r,ind,c);
        mid=r-1;
    }


    if(x>0){
        r=a[mid];
        l=r-x+1;
        ans+=f(r)-f(l-1);
    }

    return ans;
}

void solve(){   
    int n;
    long long x;
    cin>>n>>x;
    vector<long long> a(2*n,0),dp(2*n,0),dp1(2*n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[n+i]=a[i];
    }
    for(int i=0;i<dp.size();i++){
        dp1[i]=a[i]+(i>0?dp1[i-1]:0ll);
        dp[i]=f(a[i])+(i>0?dp[i-1]:0ll);
    }
    long long ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,f1(n+i,x,a,dp,dp1));
    }
    cout<<ans<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}