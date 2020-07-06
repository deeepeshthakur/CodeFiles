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

int pq(int a){
    cout<<a<<endl;
    int x;
    cin>>x;
    return x;
}

void play1(int n,int m,vector<int>& p,vector<pair<int,int>>& pr){
    sort(rfull(pr));
    vector<int> vis(2*n,true);
    int ctr=0;
    for(int i=0;i<m;i++){
        if(p[pr[i].first-1]<p[pr[i].second-1]) swap(pr[i].first,pr[i].second);
        vis[pr[i].first-1]=false;
        vis[pr[i].second-1]=false;
        int ret=pq(pr[i].first);
        ctr++;
    }
    int mx,ind;
    while(ctr<n){
        mx=0;ind=-1;
        for(int i=0;i<2*n;i++){
            if(vis[i]&&mx<p[i]){
                mx=p[i];
                ind=i+1;
            }
        }
        vis[ind-1]=false;
        vis[pq(ind)-1]=false;
        ctr++;
    }
}

void play2(int n,int m,vector<int>& p,vector<pair<int,int>>& pr){
    vector<int> vis(2*n,1);
    // sort(rfull(pr));
    for(int i=0;i<m;i++) vis[pr[i].first-1]=vis[pr[i].second-1]=2;
    int ctr=0,x;cin>>x;
    while(vis[x-1]==2 && ctr<n){
        for(int i=0;i<m;i++) 
            if(pr[i].first==x || pr[i].second==x){
                vis[pr[i].first-1]=vis[pr[i].second-1]=0;
                ctr++;
                x=pq(pr[i].first+pr[i].second-x);
                break;
            }
    }

    bool flag=true;
    while(flag && ctr<n){
        flag=false;
        vis[x-1]=0;
        for(int i=0;i<m;i++){
            if(vis[pr[i].first-1]==2 && vis[pr[i].second-1]==2){
                flag=true;
                ctr++;
                if(p[pr[i].first-1]<p[pr[i].second-1]) swap(pr[i].first,pr[i].second);
                vis[pr[i].first-1]=0;
                x=pq(pr[i].first);
                break;
            }
        }
    }

    int mx=0,ind=-1;
    while(ctr<n){
        vis[x-1]=0;
        mx=0;
        ind=-1;
        for(int i=0;i<2*n;i++){
            if(vis[i]!=0 && p[i]>mx){
                mx=p[i];
                ind=i+1;
            }
        }

        vis[ind-1]=0;
        if(ctr==n-1) cout<<ind<<endl;
        else x=pq(ind);
        ctr++;
    }
}

void solve(){
    int n,m;cin>>n>>m;
    vector<int> p(2*n,0);
    for(int i=0;i<p.size();i++) cin>>p[i];
    vector<pair<int,int>> pr(m,{0,0});
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        if(p[x-1]<p[y-1]) swap(x,y);
        pr[i]={x,y};
    }
    int t;cin>>t;
    if(t==1) play1(n,m,p,pr);
    else play2(n,m,p,pr);
}   

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}