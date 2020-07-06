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

int f(bitset<6> a, bitset<6> b, int h,int w, vector<string> g){
    for(int i=0;i<h;i++)
        if(a[i]==1)
            for(int j=0;j<w;j++) g[i][j]='.';

    for(int j=0;j<w;j++)
        if(b[j]==1)
            for(int i=0;i<h;i++) g[i][j]='.';
    
    int ans=0;
    for(int i=0;i<h;i++) for(int j=0;j<w;j++) ans+=(g[i][j]=='#'?1:0);
    return ans;
}

void solve(){
    int h,w,k;
    cin>>h>>w>>k;
    vector<string> g(h);
    for(int i=0;i<h;i++) cin>>g[i];    
    int ans=0;
    for(int i=0;i<(1<<h);i++) for(int j=0;j<(1<<w);j++){
        bitset<6> a(i),b(j);
        ans+=(f(a,b,h,w,g)==k?1:0);
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