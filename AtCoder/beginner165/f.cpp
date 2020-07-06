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

void dfs(int ind, int len, vector<bool>& vis, vector<vector<int>>& tr, vector<int>& a, vector<int>& sc){
    if(vis[ind]){
        vis[ind]=false;
        sc[ind]=len+1;
        for(int i=0;i<tr[ind].size();i++){
            if(vis[tr[ind][i]]){
                int cr=tr[ind][i];
                if(a[cr]<=a[ind]) {
                    dfs(cr,len,vis,tr,a,sc);
                }
                else{
                    dfs(cr,len+1,vis,tr,a,sc);
                }
            }

        }
    }
}


void solve(){
    int n;cin>>n;
    vector<int> a(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<vector<int>> tr(n);
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        x--;y--;
        tr[x].pb(y);
        tr[y].pb(x);
    }

    vector<bool> vis(n,true);
    vector<int> sc(n,0);
    dfs(0,0,vis,tr,a,sc);
    for(int i=0;i<n;i++) cout<<sc[i]<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}