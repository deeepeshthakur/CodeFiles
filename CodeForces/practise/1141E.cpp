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
    long long h;
    cin>>h>>n;
    vector<long long> d(n,0);
    for(int i=0;i<n;i++) cin>>d[i];
    // d[0]=-1;
    for(int i=0;i<n;i++) if(i>0) d[i]+=d[i-1];
    long long ind=0,mn=d[0];
    for(int i=0;i<n;i++){
        if(d[i]<mn){
            ind=i;
            mn=d[i];
        }
    }
    long long t=-1;
    if(h+mn<=0){
        t=0;
    }
    else
    if(d[n-1]<0){
        long long l=0,r=h/abs(d[n-1])+10,mid;
        while(r-l>1){
            mid=(l+r)/2;
            if(h+mid*d[n-1]+mn<=0) r=mid;
            else l=mid;
        }   
        if(h+mn+d[n-1]*l<=0) r=l;
        t=r;
    }

    if(t<0){
        cout<<-1<<"\n";
        return;
    } 
    h+=t*d[n-1];
    t*=n;
    for(int i=0;i<n;i++){
        if(h+d[i]<=0){
            t+=(i+1);
            cout<<t<<"\n";
            return;
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}