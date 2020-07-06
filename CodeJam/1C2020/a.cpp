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

void solve(int test_case){
    int x,y;
    string m;
    cin>>x>>y;
    cin>>m;
    int ans=m.size()+100;
    if(x+y<=0) ans=0;
    for(int i=0;i<m.size();i++){
        if(m[i]=='N') y++;
        if(m[i]=='S') y--;
        if(m[i]=='E') x++;
        if(m[i]=='W') x--;
        if(abs(x)+abs(y)<=i+1){
            ans=min(ans,i+1);
        }
    }
    if(ans<=m.size()){
        cout<<"Case #"<<test_case<<": "<<ans<<"\n";
    }
    else{
        cout<<"Case #"<<test_case<<": "<<"IMPOSSIBLE"<<"\n";
    }
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