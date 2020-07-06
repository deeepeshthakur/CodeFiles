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
    int n;
    cin>>n;
    vector<int> p(n,0),v(n,0);
    for(int i=0;i<n;i++) cin>>p[i];
    for(int i=0;i<n;i++) p[i]--;
    for(int i=0;i<n;i++) cin>>v[i];
    vector<vector<int>> qs;
    vector<bool> vis(n,true);
    for(int i=0;i<n;i++){
        if(vis[i]){
            vis[i]=false;
            vector<int> q;
            int st=i,curr=p[i];
            q.push_back(i);
            while(curr!=st){
                vis[curr]=false;
                q.push_back(curr);
                curr=p[curr];
            }
            qs.push_back(q);
        }
    }
    // cout<<qs.size()<<"\n";
    int ctr=0;
    for(int i=0;i<qs.size();i++){
        if(i+1<qs.size()){
            p[qs[i].back()]=qs[i+1][0];
            ctr++;
        }
    }
    if(qs.size()>1){
        ctr++;
        p[qs.back().back()]=qs[0][0];
    }

    int st=0,curr=p[0],state=0;
    if(v[0]==1) state=1-state;
    while(curr!=st){
        if(v[curr]==1) state=1-state;
        curr=p[curr];
    }

    if(state==0) ctr++;
    cout<<ctr<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}