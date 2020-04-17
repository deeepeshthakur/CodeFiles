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

void print_vec(vector<int>& a, int n=-1){
    n=(n==-1?a.size():n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<(i<n-1?" ":"\n");
}

void get_input(int n, vector<vector<int>>& inp_tree){
    int x,y;
    for(int i=0;i<n-1;i++){
        cin>>x>>y;
        inp_tree[x-1].pb(y-1);
        inp_tree[y-1].pb(x-1);
    }
}

void dfs(int ind, int parent, vector<vector<int>>& inp_tree, vector<bool>& vis, vector<long long>& weights, vector<long long>& path_length, vector<int>& parent_element, vector<int>& level){
    if(vis[ind]){
        vis[ind]=false;
        if(parent>=0){
            parent_element[ind]=parent;
            path_length[ind]=path_length[parent];
            level[ind]=level[parent]+1;
        }
        path_length[ind]+=weights[ind];
        for(int i=0;i<inp_tree[ind].size();i++){
            dfs(inp_tree[ind][i],ind,inp_tree,vis,weights,path_length,parent_element,level);
        }
    }
}

void fill_dp(int ind, vector<bool>& vis, vector<int>& parent_element, vector<vector<int>>& dp){
    if(!vis[ind]){
        vis[ind]=true;
        if(parent_element[ind]>=0){
            if(!vis[parent_element[ind]])  fill_dp(parent_element[ind],vis,parent_element,dp);
            dp[ind][0]=parent_element[ind];
            for(int i=1;i<dp[ind].size() && dp[ind][i-1]!=-1;i++){
                dp[ind][i]=dp[dp[ind][i-1]][i-1];
            }
        }
    }
}

int common_an(int a, int b, vector<int>& level_vector, vector<int>& parent_element, vector<vector<int>>& dp){
    cout<<a<<" "<<b<<endl;
    if(level_vector[a]>level_vector[b]){
        swap(a,b);
    }

    while(level_vector[b]>level_vector[a]){
        int j=0;
        while(dp[b][j+1]!=-1 && level_vector[dp[b][j+1]]>=level_vector[a]) j++;
        b=dp[b][j];
    }
    
    while(a!=b){
        int x=-1;
        while(dp[a][x+1]!=-1 && dp[a][x+1]!=dp[b][x+1]) x++;
        a=parent_element[dp[a][x+1]];
        b=parent_element[dp[b][x+1]];
    }
    return a;
}

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> inp_tree(n);
    vector<long long> weights(n);
    get_input(n,inp_tree);
    for(int i=0;i<n;i++)
        cin>>weights[i];
    vector<long long> path_length(n,0ll);

    int lim=2,mx_n=1;
    while(mx_n<=n){
        mx_n*=2;
        lim++;
    }

    vector<bool> vis(n,true);
    vector<int> parent_element(n,-1),level_vec(n,0);
    dfs(0,-1,inp_tree,vis,weights,path_length,parent_element,level_vec);
    vector<vector<int>> dp(n,vector<int>(lim,-1));
    for(int i=0;i<n;i++){
        fill_dp(i,vis,parent_element,dp);
    }
    print_vec(parent_element);
    print_vec(level_vec);
    for(int i=0;i<n;i++){
        print_vec(dp[i]);
    }

    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int u,v;
        long long ans=0;
        cin>>u>>v;
        ans=path_length[u-1]+path_length[v-1];
        u=common_an(u-1,v-1,level_vec,parent_element,dp);
        ans+=weights[u]-2*path_length[u];
        cout<<ans%MOD<<"\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
