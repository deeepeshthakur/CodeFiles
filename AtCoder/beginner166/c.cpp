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
    int n,m;cin>>n>>m;
    vector<int> h(n,0);
    for(int i=0;i<n;i++) cin>>h[i];
    vector<vector<int>> gr(n);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        x--;y--;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    vector<int> sc(n,0);
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<gr[i].size();j++){
            if(h[i]<=h[gr[i][j]]) sc[i]++;
        }
        if(sc[i]==0) ans++;
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