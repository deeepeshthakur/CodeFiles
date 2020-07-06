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

long double f(int t, int h, int c, long long m){
    return 1.0*abs(2ll*m*t+t-m*c-m*h-h)/(2ll*m+1);
}

bool cmp(const pair<long double,long long>& a,const pair<long double,long long>& b){
    return a.first<b.first || (a.first==b.first && a.second<b.second);
}

void solve(){
    long long h,c,t;
    cin>>h>>c>>t;
    long double del_min=abs(2*t-h-c),mul=2;
    long long ans=2;
    if(mul*abs(h-t)<=del_min){
        del_min=abs(h-t);
        mul=1;
        ans=1;
    }
    if(2*t-h-c!=0 && 2*t>h+c){
        long long m,t1=(h-t)/(2*t-c-h);
        for(m=max(1ll,t1-10);m<=t1+10;m++){
            if(m>0 && mul*abs(m*h+m*c-2ll*m*t+h-t)<(2*m+1)*del_min){
                del_min=abs(m*h+m*c-2ll*m*t+h-t);
                mul=2*m+1;
                ans=mul;
            }
        }
    }

    cout<<ans<<endl;
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