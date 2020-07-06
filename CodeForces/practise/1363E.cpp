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
    long long a;
    int b,c,level;
    vector<int> e;
};

void dfs(int ind, int level, vector<bool>& v, vector<node>& gr){
    if(v[ind]){
        v[ind]=false;
        gr[ind].level=level;
        for(int i=0;i<gr[ind].e.size();i++){
            dfs(gr[ind].e[i],level+1,v,gr);
        }
    }
}

bool cmp(const pair<pair<int,int>,int>& aa,const pair<pair<int,int>,int>& bb){
    pair<int,int> a=aa.first,b=bb.first;
    return a.first<b.first || (a.first == b.first && a.second>b.second);
}

void final_dfs(int ind, vector<bool>& v, vector<node>& gr, long long &ans, int &x1, int &x2, vector<bool>& v2){
    if(v[ind]){
        v[ind]=false;
        int a=0,b=0;
        for(int i=0;i<gr[ind].e.size();i++)
            final_dfs(gr[ind].e[i],v,gr,ans,a,b,v2);
        if(gr[ind].b!=gr[ind].c){
            if(gr[ind].b==1){
                a++;
            }
            else{
                b++;
            }
        }
        if(v2[ind]){
            if(a>0 && b>0){
                int tmp=min(a,b);
                ans+=2ll*gr[ind].a*tmp;
                a-=tmp;
                b-=tmp;
            }
        }
        x1+=a;
        x2+=b;
    }
}

void solve(){
    int n;
    cin>>n;
    vector<node> gr(n);
    for(int i=0;i<n;i++){
        long long a;
        int b,c;
        cin>>a>>b>>c;
        gr[i].a=a;
        gr[i].b=b;
        gr[i].c=c;
        gr[i].level=0;
        gr[i].e.resize(0);
    }
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        gr[x-1].e.pb(y-1);
        gr[y-1].e.pb(x-1);
    }
    int ctr=0;
    for(int i=0;i<n;i++) ctr+=gr[i].b-gr[i].c;
    if(ctr!=0){
        cout<<"-1\n";
        return;
    }

    long long ans=0;
    vector<bool> v(n,true);
    dfs(0,1,v,gr);
    vector<pair<pair<int,int>,int>> srt(n,{{0,0},0});
    for(int i=0;i<n;i++){
        srt[i]={{gr[i].a,gr[i].level},i};
    }
    sort(full(srt),cmp);
    vector<bool> v2(n,false);
    int curr=-1;
    for(int i=0;i<n;i++){
        if(curr==-1 || srt[i].first.second<=curr){
            v2[srt[i].second]=true;
            if(curr!=-1) curr=min(curr,srt[i].first.second);
            else curr=srt[i].first.second;
        }
    }
    vector<bool> v1(n,true);
    int xxx=0,yyy=0,www=0,zzz=0;
    final_dfs(0,v1,gr,ans,xxx,yyy,v2);
    cout<<ans<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}