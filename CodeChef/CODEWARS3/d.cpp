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


#define MAXN 300000 
#define level 30
  
vector <int> tree[MAXN]; 
int depth[MAXN]; 
int parent[MAXN][level]; 
  
void dfs(int cur, int prev) 
{ 
    depth[cur] = depth[prev] + 1; 
    parent[cur][0] = prev; 
    for (int i=0; i<tree[cur].size(); i++) 
    { 
        if (tree[cur][i] != prev) 
            dfs(tree[cur][i], cur); 
    } 
} 

void precomputeSparseMatrix(int n) 
{ 
    for (int i=1; i<level; i++) 
    { 
        for (int node = 1; node <= n; node++) 
        { 
            if (parent[node][i-1] != -1) 
                parent[node][i] = 
                    parent[parent[node][i-1]][i-1]; 
        } 
    } 
} 

int lca(int u, int v) 
{ 
    if (depth[v] < depth[u]) 
        swap(u, v); 
  
    int diff = depth[v] - depth[u]; 
    for (int i=0; i<level; i++) 
        if ((diff>>i)&1) 
            v = parent[v][i]; 
    if (u == v) 
        return u; 
    for (int i=level-1; i>=0; i--) 
        if (parent[u][i] != parent[v][i]) 
        { 
            u = parent[u][i]; 
            v = parent[v][i]; 
        } 
  
    return parent[u][0]; 
} 
  
void addEdge(int u,int v) { 
    tree[u].push_back(v); 
    tree[v].push_back(u); 
} 

int main() 
{ 
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    memset(parent,-1,sizeof(parent)); 
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n-1;i++){
        int x,y;cin>>x>>y;
        addEdge(x,y);
    }
    depth[0] = 0; 
  
    dfs(1,0); 
    precomputeSparseMatrix(n); 
  
    for(int i=0;i<q;i++){
        int k;cin>>k;
        vector<int> vv(k,0);
        for(int j=0;j<k;j++) cin>>vv[j];
        int lca_node=vv[0];
        for(int j=0;j<k;j++) lca_node=lca(lca_node,vv[j]);
        bool flag=false;
        for(int j=0;j<k;j++){
            if(vv[j]==lca_node){
                flag=true;
                j=k+100;
            }
        }
        if(flag){
            cout<<lca_node<<"\n";
        }
        else{
            cout<<"-1\n";
        }
    }
    return 0; 
} 
