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
    map<int,vector<int>> ht;
    map<int,bool> vis;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        if(vis.find(x)==vis.end()){
            ht.insert({x,vector<int>{}});
            vis.insert({x,true});
        }
        if(vis.find(y)==vis.end()){
            ht.insert({y,vector<int>{}});
            vis.insert({y,true});
        }
        ht[x].push_back(y);
        ht[y].push_back(x);
    }
    int st;
    for(auto itr=ht.begin();itr!=ht.end();itr++){
        if(itr->second.size()==1){
            st=itr->first;
        }
    }
    queue<int> qu;
    while(vis[st]){
        qu.push(st);
        vis[st]=false;
        auto itr=ht[st];
        for(int i=0;i<itr.size();i++){
            if(vis[itr[i]]){
                st=itr[i];
                break;
            }
        }
    }
    while(!qu.empty()){
        cout<<qu.front()<<" ";
        qu.pop();
    }
    cout<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}