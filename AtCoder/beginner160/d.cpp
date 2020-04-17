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

void bfs(int ind, queue<int>& bfs_q, vector<int>& path, int n, int x, int y){
    if(y==ind){
        swap(x,y);
    }
    if(ind>0 && path[ind-1]==-1){
        path[ind-1]=path[ind]+1;
        bfs_q.push(ind-1);
    }

    if(ind<n-1 && path[ind+1]==-1){
        path[ind+1]=path[ind]+1;
        bfs_q.push(ind+1);
    }

    if(ind==x && path[y]==-1){
        path[y]=path[ind]+1;
        bfs_q.push(y);
    }
}

void solve(){
    int n,k,x,y;
    cin>>n>>x>>y;
    x--;
    y--;
    vector<vector<int>> path(n,vector<int>(n,-1));
    vector<int> ans(n,0);
    for(int i=0;i<n;i++){
        queue<int> bfs_q;
        bfs_q.push(i);
        path[i][i]=0;
        while(!bfs_q.empty()){
            bfs(bfs_q.front(),bfs_q,path[i],n,x,y);
            bfs_q.pop();
        } 
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ans[path[i][j]]++;
        }
    }

    for(int i=1;i<n;i++){
        cout<<ans[i]<<"\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}