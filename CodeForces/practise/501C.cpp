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

// struct cmp{
//     bool operator()(const vector<int>& a,const vector<int>& b){
//         return a[0]>b[0];
//     }
// };

void solve(){
    int n;cin>>n;
    vector<pair<int,int>> a(n,{0,0});
    for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second;
    vector<bool> vis(n,true);

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i=0;i<n;i++){
        pq.push({a[i].first,i});
    }

    set<pair<int,int>> ed;
    int u,v;
    while(!pq.empty()){
        auto t=pq.top();
        pq.pop();
        if(t.first>0){
            if(vis[t.second]){
                u=t.second;
                v=a[t.second].second;
                if(vis[v]){
                    a[v].second=(a[v].second^u);
                    a[v].first--;
                    pq.push({a[v].first,v});
                }
                ed.insert({min(u,v),max(u,v)});
            }
        }
        else{
            vis[t.second]=false;
        }
    }
    cout<<ed.size()<<"\n";
    for(auto itr=ed.begin();itr!=ed.end();++itr){
        auto x=*itr;
        cout<<x.first<<" "<<x.second<<"\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}