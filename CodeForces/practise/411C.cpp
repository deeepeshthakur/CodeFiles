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

int play(pair<int,int>& a,pair<int,int>& b, pair<int,int>& c,pair<int,int>& d){
    if(a.second>d.first && b.first>c.second) return 1;
    if(a.second<d.first && b.first<c.second) return -1;
    return 0;
}

int f(pair<int,int>& a,pair<int,int>& b, pair<int,int>& c,pair<int,int>& d){
    int i=play(a,b,c,d),j=play(a,b,d,c);
    if(i==1&&j==1) return 1;
    if(i==-1 || j==-1) return -1;
    return 0;
}

void solve(){
    vector<pair<int,int>> a(4,{0,0});
    for(int i=0;i<4;i++) cin>>a[i].first>>a[i].second;
    int i=f(a[0],a[1],a[2],a[3]),j=f(a[1],a[0],a[2],a[3]);
    if(i==1 || j==1) cout<<"Team 1\n";
    else{
        if(i==-1 && j==-1) cout<<"Team 2\n";
        else cout<<"Draw\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}