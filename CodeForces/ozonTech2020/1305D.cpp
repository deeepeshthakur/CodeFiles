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

int query(int a,int b){
    cout<<"? "<<a+1<<" "<<b+1<<endl;
    cin>>a;
    return a-1;
}

void dfs(int ind, int curr, vector<bool>& v, vector<vector<int>>& t, vector<int>& dist){
    if(v[ind]){
        v[ind]=false;
        dist[ind]=curr;
        for(int i=0;i<t[ind].size();i++){
            dfs(t[ind][i],curr+1,v,t,dist);
        }
    }
}

void dfs1(int ind, vector<bool>& v, vector<vector<int>>& t){
    if(v[ind]){
        v[ind]=false;
        for(int i=0;i<t[ind].size();i++){
            dfs1(t[ind][i],v,t);
        }
    }
}

int f(int n, vector<bool> v, vector<vector<int>> t, vector<int> r){
    if(r.size()==1) return r[0];
    vector<int> dist(n,-1),dist2(n,-1);
    vector<bool> v1(v),v2(v);
    dfs(r[0],0,v1,t,dist);
    int curr=r[0],mx=0;
    for(int i=0;i<n;i++) if(v[i] && dist[i]>mx){
        mx=dist[i];
        curr=i;
    }
    dfs(curr,0,v2,t,dist2);
    int curr2=curr;mx=0;
    for(int i=0;i<n;i++) if(v[i] && dist2[i]>mx){
        mx=dist2[i];
        curr2=i;
    }
    int lca = query(curr,curr2);
    if(lca==curr || lca==curr2) return lca;
    vector<bool> v3(v),v4(v);v3[lca]=v4[lca]=false;
    for(int i=0;i<t[lca].size() && v3[curr];i++){
        dfs1(t[lca][i],v3,t);
        if(!v3[curr]){
            v[lca]=false;
            dfs1(t[lca][i],v,t);
        }
        v[lca]=true;
    }

    for(int i=0;i<t[lca].size() && v4[curr2];i++){
        dfs1(t[lca][i],v4,t);
        if(!v4[curr2]){
            v[lca]=false;
            dfs1(t[lca][i],v,t);
        }
        v[lca]=true;
    }

    vector<vector<int>> nt(n);
    for(int i=0;i<n;i++) if(v[i])
        for(int j=0;j<t[i].size();j++) if(v[t[i][j]]) nt[i].pb(t[i][j]);
    vector<int> nr;
    for(int i=0;i<n;i++) if(v[i] && nt[i].size()<=1) nr.pb(i);
    
    return f(n,v,nt,nr);
}

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> tr(n+1);
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;x--;y--;
        tr[x].pb(y);
        tr[y].pb(x);
    }
    vector<bool> v(n,true);
    vector<int> rts;
    for(int i=0;i<n;i++) if(tr[i].size()==1) rts.push_back(i);
    int ans=f(n,v,tr,rts)+1;
    cout<<"! "<<ans<<endl;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}