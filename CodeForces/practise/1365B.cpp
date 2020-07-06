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
    cin>>n;
    int a=0,b=0;
    vector<pair<int,int>> x(n,{0,0});
    for(int i=0;i<n;i++) cin>>x[i].first;
    for(int i=0;i<n;i++) cin>>x[i].second;
    for(int i=0;i<n;i++) if(x[i].second==0) a++; else b++;
    if(a==0 || b==0){
        bool flag=true;
        for(int i=1;i<n;i++) if(x[i].first<x[i-1].first) flag=false;
        if(!flag){
            cout<<"No\n";
            return;
        }
    }

    cout<<"Yes\n";
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