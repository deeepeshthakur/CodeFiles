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
const long double hf=1.0/2.0,on=1.0;

long double gp(int r, int d){
    return pow(hf,(on)*(r+d-2));
}

void solve(int test_case){
    int w,h,l,u,r,d;cin>>w>>h>>l>>u>>r>>d;
    long double ans=0.0;
    if((l!=1 || u!=1) && (r!=w || d!=h) && (l!=1 || r!=w) && (u!=1 || d!=h)){
        long double mul=on,curr;
        int d_0=max(0,u-2),r_0=max(0,l-2),n_0=d_0+r_0,den_0=min(r_0,d_0);
        // cout<<n_0<<" "<<den_0<<"\n";
        for(int i=den_0;i>0;i--){
            // cout<<"HERE\n";
            mul*=(on*(n_0-den_0+i)/(on*i));
        }
        // cout<<mul<<"\n";
        curr=mul;
        if(l>1){
            if(u==1){
                ans+=gp(u,l);
            }
            for(int i=max(2,u);i<=d && i<h;i++){
                curr*=(on*(i-1+r_0)/(on*(i-1)));
                ans+=(curr*gp(i,l-1))*hf;
            }
        }
        // cout<<ans<<"\n";
        curr=mul;
        if(u>1){
            if(l==1){
                ans+=gp(l,u);
            }
            for(int i=max(2,l);i<=r && i<w;i++){
                // cout<<ans<<"\n";
                curr*=(on*(i-1+d_0)/(on*(i-1)));
                ans+=(curr*gp(i,u-1))*hf;
            }
        }
        // cout<<ans<<"\n";
        if(r==w){
            mul=on;
            curr=0.0;
            for(int i=1;i<u;i++){
                curr+=(mul*gp(i+r-1,0))*hf;
                mul=mul*((on*(max(0,r-2)+i))/(on*i));
            }
            ans+=curr;
        }

        if(d==h){
            mul=on;
            curr=0.0;
            for(int i=1;i<l;i++){
                curr+=(mul*gp(i+d-1,0))*hf;
                mul=mul*((on*(max(0,d-2)+i))/(on*i));
            }
            ans+=curr;
        }
        ans=(1.0-ans);
        if(ans<0.0)
            ans=0.0;
    }
    cout<<scientific<<setprecision(10)<<"Case #"<<test_case<<": "<<ans<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        solve(i);
    }
    return 0;
}