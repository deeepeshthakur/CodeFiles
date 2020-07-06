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
    int n,x;
    cin>>n>>x;
    vector<int> c(300,0);
    for(int i=0;i<n;i++) cin>>c[i];
    for(int i=0;i<n;i++) c[i]*=(n-i);
    sort(full(c));
    int ctr=0;
    for(int i=0;i<300;i++) if(c[i]>0 && x>=c[i]){ctr++;x-=c[i];}
    cout<<ctr<<"\n";
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}