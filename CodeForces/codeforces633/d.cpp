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

void dfs(int ind, int parent, int ht, vector<bool>& vis, vector<vector<int>>& tr, vector<bool>& val,vector<int>& height){
    if(vis[ind]){
        vis[ind]=false;
        int ctr=-1;
        for(int i=0;i<tr[ind].size();i++){
            if(vis[tr[ind][i]]){
                dfs(tr[ind][i],parent,ht,vis,tr,val,height);
                if(i==0){
                    ctr=(height[tr[ind][i]]+1)%2;
                }
                else{
                    
                }
            }
        }

    }
}

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> tr(n);
    vector<bool> vis(n,true),val(n,true);
    vector<int> height(n,0);
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        tr[x-1].pb(y-1);
        tr[y-1].pb(x-1);
    }

    int root=-1;
    for(int i=0;i<n;i++){
        if(tr[i].size()==1){
            root=i;
            break;
        }
    }

    dfs(root,-1,0,vis,tr,val,height);

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}