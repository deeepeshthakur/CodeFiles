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

long long check_all_pairs(long long l,long long r){
    int ans=0;
    for(int i=l;i<=r;i++){
        for(int j=l;j<=r;j++){
            ans=max(ans,i^j);
        }
    }
    return 1ll*ans;
}

long long rec1(long long a){
    if(a<=1) return a;
    long long mul=1;
    while(a>=mul) mul*=2;
    mul/=2;
    return (mul^(mul-1));
}

long long rec_fun(long long l,long long r){
    long long ans=0;
    for(long long i=2;i<=r;i*=2ll){
        long long x=i,y=x-1;
        if(l<=y && x<=r){
            ans=max(ans,x^y);
        }
        else{
            if(l<=x){
                ans=max(ans,rec1(r-x));
            }
            else
            {
                    if(x<=l && r<2ll*x){
                        ans=max(ans,rec_fun(l-x,r-x));
                    }
            }
            
        }
    }
    return ans;
}

void solve(){
    long long l,r;
    cin>>l>>r;
    if(r<=1000){
        cout<<check_all_pairs(l,r)<<"\n";
        return;
    }
    long long ans=rec_fun(l,r);

    cout<<ans<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}