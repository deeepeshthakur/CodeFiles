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
    long long x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
    set<tuple<int,int,int>> st;
    int n;cin>>n;
    long long ans=0;
    for(int i=0;i<n;i++){
        long long a,b,c;cin>>a>>b>>c;
        if(((a*x1+b*y1+c)<0 &&(a*x2+b*y2+c)>0)||((a*x1+b*y1+c)>0 &&(a*x2+b*y2+c)<0)) ans++;

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