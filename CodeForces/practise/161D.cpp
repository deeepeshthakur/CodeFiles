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


void dfs(int ind, int parent, int k, vector<bool>& v, vector<vector<int>>& tr, vector<vector<int>>& c, vector<int>& p){
    if(v[ind]){
        v[ind]=false;
        p[ind]=parent;
        for(int i=0;i<tr[ind].size();i++) dfs(tr[ind][i],ind,k,v,tr,c,p);
        for(int i=0;i<tr[ind].size();i++)
            if(tr[ind][i]!=parent)
                for(int j=0;j<k;j++)
                    c[ind][j+1]+=c[tr[ind][i]][j];
    }
}

void redistribute(int ind, int k, vector<bool>& v, vector<vector<int>>& tr, vector<vector<int>>& c, vector<int>& p){
    if(v[ind]){
        v[ind]=false;
        if(p[ind]>=0)
            for(int i=k;i>=0;i--)
                c[ind][i]+=(i>0?c[p[ind]][i-1]:0)-(i>1?c[ind][i-2]:0);
        for(int i=0;i<tr[ind].size();i++) redistribute(tr[ind][i],k,v,tr,c,p);
    }
}

void solve(){   
    int n,k;
    cin>>n>>k;
    vector<vector<int>> tr(n),calc(n,vector<int>(k+1,0));
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        tr[x-1].push_back(y-1);
        tr[y-1].push_back(x-1);
    }
    for(int i=0;i<n;i++) calc[i][0]=1;
    vector<bool> v1(n,true),v2(n,true);
    vector<int> parent(n,-1);
    dfs(0,-1,k,v1,tr,calc,parent);
    redistribute(0,k,v2,tr,calc,parent);
    long long ans=0;
    for(int i=0;i<n;i++) ans+=calc[i][k];
    if(ans%2==1) {cout<<"-1\n"; return;}
    cout<<ans/2<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}