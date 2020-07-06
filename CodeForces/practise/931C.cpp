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
    int n;
    cin>>n;
    vector<long long> x(n,0);
    for(int i=0;i<n;i++) cin>>x[i];
    long long mx=-int(1e9),mn=int(1e9);
    for(int i=0;i<n;i++){
        mx=max(mx,x[i]);
        mn=min(mn,x[i]);
    }
    int ans=0;
    vector<long long> y;
    if(mx-mn==2){
        long long md=mn+1;
        for(int i=0;i<n;i++) x[i]-=md;
        int a=0,b=0,c=0,sm=0;
        for(int i=0;i<n;i++){
            sm+=x[i];
            if(x[i]==1) a++;
            if(x[i]==-1) b++;
            if(x[i]==0) c++;
        }
        if(sm>0) a-=abs(sm);
        if(sm<0) b-=abs(sm);
        ans=max(a+b,(c/2)*2);
        if(a+b<=c-c%2){
            for(int i=0;i<a;i++){
                y.pb(-1);
                y.pb(1);
            }
            for(int i=0;i<c/2;i++){
                y.pb(-1);
                y.pb(1);
            }
            if(c%2==1) y.pb(0);
            for(int i=0;i<abs(sm);i++) y.pb((sm>0)?1:-1);
        }
        else{
            for(int i=0;i<n;i++){
                if(abs(sm)>i) y.pb((sm>0)?1:-1);
                else y.pb(0);
            }
        }
        for(int i=0;i<n;i++) y[i]+=md;
    }
    else{
        for(int i=0;i<n;i++) y.pb(x[i]);
    }
    cout<<n-ans<<"\n";
    for(int i=0;i<n;i++) cout<<y[i]<<(i+1<n?" ":"\n");
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}