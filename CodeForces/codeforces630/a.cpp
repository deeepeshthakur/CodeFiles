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
    int a,b,c,d;
    int x,y,x1,y1,x2,y2;
    cin>>a>>b>>c>>d;
    cin>>x>>y>>x1>>y1>>x2>>y2;
    bool flag=true;

    if(c>0 || d>0){
        if(y2-y1<=0)
            flag=false;
    }

    if(a>0 || b>0){
        if(x2-x1<=0)
            flag=false;
    }

    if(flag){
        x=x-a+b;
        y=y-c+d;
        if(x1<=x && x<=x2 && y1<=y && y<=y2){
            cout<<"YES\n";
            return;
        }
    }

    cout<<"NO\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}