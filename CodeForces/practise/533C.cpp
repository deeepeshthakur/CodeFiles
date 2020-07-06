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
    int a,b,x,y;
    cin>>a>>b>>x>>y;
    vector<pair<int,int>> mvs;
    while(x!=0 || y!=0){
        mvs.pb({x,y});
        if(x&&y){
            x--;y--;
        }
        else{
            if(x) x--;
            else y--;
        }
    }
    mvs.pb({0,0});
    bool flag=a+b<mvs.size();
    for(int i=0;i<mvs.size();i++){
        if(mvs[i].first<=a && mvs[i].second<=b && abs(mvs[i].first-a)+abs(mvs[i].second-b)<=i) flag=true;
    }
    if(flag) cout<<"Polycarp\n";
    else cout<<"Vasiliy\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}