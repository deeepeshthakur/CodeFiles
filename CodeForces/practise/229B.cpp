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

struct node{
    int ind;
    long long tm;
};

node gn(int ii=0,long long tt=0){
    node a;
    a.tm=tt;a.ind=ii;
    return a;
}

struct cmp{
    bool operator()(const node& a,const node& b){
        return a.tm>b.tm;
    }
};

void bfs(int ind,long long tm, vector<vector<pair<int,long long>>>& gr, vector<long long>& tu,priority_queue<node,vector<node>,cmp>& pq, vector<bool>& vis, vector<long long>& ta){
    if(vis[ind]){
        vis[ind]=false;
        ta[ind]=tm;
        if(tu.size()>0) while(binary_search(full(tu),tm)) tm++;
        for(int i=0;i<gr[ind].size();i++){
            node a=gn(gr[ind][i].first,tm+gr[ind][i].second);
            // cout<<a.ind<<" "<<a.tm<<endl;
            if(vis[gr[ind][i].first]) pq.push(a);
        }
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,long long>>> gr(n);
    vector<vector<long long>> tu(n);
    for(int i=0;i<m;i++){
        int x,y,c;
        cin>>x>>y>>c;
        gr[x-1].pb({y-1,c});
        gr[y-1].pb({x-1,c});
    }
    for(int i=0;i<n;i++){
        int k,x;cin>>k;
        while(k--){
            cin>>x;
            tu[i].pb(x);
        }
        if(tu[i].size()>1) sort(full(tu[i]));
    }
    priority_queue<node,vector<node>,cmp> pq;
    vector<bool> vis(n,true);
    vector<long long> tarray(n,-1);
    pq.push(gn(0,0ll));
    while(!pq.empty()&&tarray[n-1]==-1){
        auto x=pq.top();
        // cout<<pq.size()<<" "<<x.ind<<" "<<x.tm<<endl;
        pq.pop();
        if(vis[x.ind]) bfs(x.ind,x.tm,gr,tu[x.ind],pq,vis,tarray);
    }
    cout<<tarray[n-1]<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}