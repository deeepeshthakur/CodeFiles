#include<bits/stdc++.h>
#define ll int
#define pll std::pair<ll,ll>
#define rep(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define per(i,a,b) for(ll i=(ll)a;i>(ll)b;i--)
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
int con1=100000;

int f102(int a){
    int b=1,ans=0;
    while(a){
        ans+=(a%10)*b;
        b*=2;
        a/=10;
    }
    return ans;
}

void f101(){
    std::vector<std::pair<int,int>> db{};
    rep(i,0,con1){
        db.pb({f102(i),i});
    }
    int a=0;
    std::sort(full(db));
    rep(i,0,20){0
        if(i&&db[i-1].F==db[i].F){
            // if(db[i].S%10==0)
            std::cout<<" "<<db[i].S;
        }
        else{
            std::cout<<"\n"<<db[i].F<<"   ";
            // if(db[i].S%10==0) 
                std::cout<<db[i].S;
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    f101();
    return 0;
}