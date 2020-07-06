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
    vector<vector<int>> a;
    for(int i=1;i<=1000;i++){
        a.pb({i,1,i,2});
    }
    for(int i=1000;i>=1;i--){
        a.pb({i,1,i,2});
    }
    cout<<a.size()<<"\n";
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[i].size();j++) cout<<a[i][j]<<" ";
        cout<<"\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}