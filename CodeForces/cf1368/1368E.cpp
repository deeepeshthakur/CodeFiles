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

void bdfs(int ind,vector<vector<int>>& gr, vector<int>& ht){
    if(ht[ind]==-1){
        int mx=0;
        for(int i=0;i<gr[ind].size();i++){
            bdfs(gr[ind][i],gr,ht);
            mx=max(mx,ht[gr[ind][i]]);
        }
        ht[ind]=mx+1;
    }
}

struct pair_q{
    bool operator()(const pair<int,int>& a, const pair<int,int>& b){
        return a.second>b.second;
    }
};

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> gr(n),p(n);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        x--;y--;
        p[y].push_back(x);
        gr[x].push_back(y);
    }

    vector<int> ht(n,-1);
    for(int i=0;i<n;i++){   
        bdfs(i,p,ht);
    }
    vector<int> ans;
    vector<bool> vis(n,true);
    priority_queue<pair<int,int>,vector<pair<int,int>>,pair_q> pq;
    for(int i=0;i<n;i++){
        pq.push({i,ht[i]});
    }
    while(!pq.empty()){
        if(!vis[pq.top().first]){
            while(!pq.empty() && !vis[pq.top().first]) pq.pop();
        }
        if(!pq.empty()){
            int curr=pq.top().second;
            vector<vector<int>> t(2);
            while(!pq.empty() && curr==pq.top().second){
                if(vis[pq.top().first])
                    t[0].push_back(pq.top().first);
                pq.pop();
            }
            for(int i=0;i<1;i++){
                for(int j=0;j<t[i].size();j++){
                    for(int k=0;k<gr[t[i][j]].size();k++) 
                        if(vis[gr[t[i][j]][k]])
                            t[i+1].pb(gr[t[i][j]][k]);
                }
            }
            set<int> st;
            for(int i=0;i<t[1].size();i++){
                for(int j=0;j<gr[t[1][i]].size();j++){
                    if(vis[gr[t[1][i]][j]])
                        st.insert(gr[t[1][i]][j]);
                }
            }

            for(int i=0;i<t[1].size();i++){
                if(st.find(t[1][i])==st.end()){
                    for(int j=0;j<gr[t[1][i]].size();j++){
                        if(vis[gr[t[1][i]][j]]){
                            ans.push_back(gr[t[1][i]][j]);
                            vis[gr[t[1][i]][j]]=false;
                        }
                    }
                }
            }

            for(int i=0;i<2;i++){
                for(int j=0;j<t[i].size();j++) vis[t[i][j]]=false;
            }                
        }
    }
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++) cout<<ans[i]+1<<(i+1<ans.size()?" ":"\n");

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}