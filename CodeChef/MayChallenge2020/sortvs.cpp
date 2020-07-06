#include<bits/stdc++.h>
using namespace std;

void dfs(int ind,int par, vector<bool>& v,vector<int>& cluster, vector<vector<int>>& gr){
    if(v[ind]){
        v[ind]=false;
        cluster[ind]=par;
        for(int i=0;i<gr[ind].size();i++) dfs(gr[ind][i],par,v,cluster,gr);
    }
}

void print_vec(vector<int>& a, int n=-1){
    n=(n==-1?a.size():n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<(i<n-1?" ":"\n");
}

void dfs1(int ind,int parent,vector<vector<bool>>& gr, vector<bool>& vis, pair<int,int>& ans){
    vis[ind]=false;
    for(int i=0;i<gr[ind].size();i++)
        if(parent!=i && gr[ind][i] && !vis[i] && ans.first==-1 && ans.second==-1)
            ans={parent,i};
    for(int i=0;i<gr[ind].size();i++)
        if(gr[ind][i] && vis[i])
            dfs1(i,ind,gr,vis,ans);
}

bool start_dfs(int ind,vector<vector<bool>>& gr, vector<bool>& vis,pair<int,int>& ans){
    dfs1(ind,ind,gr,vis,ans);
    if(ans.first!=-1 && ans.second!=-1) return true;
    return false;
}

pair<int,int> cycle_find(int n,vector<vector<bool>>& gr){
    vector<bool> vis(n,true);
    for(int i=0;i<n;i++){
        if(vis[i]){
            pair<int,int> ret{-1,-1};
            bool flag=start_dfs(i,gr,vis,ret);
            if(flag) return ret;
        }
    }
    return {-1,-1};
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n,m;cin>>n>>m;
        vector<int> perm(n,0);
        for(int i=0;i<n;i++) {cin>>perm[i];perm[i]--;}
        vector<vector<int>> gr(n);
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            gr[x-1].push_back(y-1);
            gr[y-1].push_back(x-1);
        }
        vector<bool> visited(n,true);
        vector<int> cluster(n,-1);
        int ctr=0,tm=0;
        vector<int> pos(n,0);
        for(int i=0;i<n;i++) pos[i]=i;
        for(int i=0;i<n;i++) if(visited[i]) dfs(i,ctr++,visited,cluster,gr);

        bool flag=true;
        while(flag){
            flag=false;
            for(int i=0;i<n;i++)
                if(pos[i]!=perm[i] && cluster[pos[i]]==cluster[perm[i]])
                    for(int j=0;j<n;j++)
                        if(j!=i && pos[j]!=perm[j] && pos[j]==perm[i]){
                            flag=true;
                            swap(pos[i],pos[j]);
                            i=j=n+1;
                        }
            if(!flag){
                for(int i=0;i<n;i++)
                    if(pos[i]!=perm[i] && cluster[pos[i]]!=cluster[perm[i]])
                        for(int j=0;j<n;j++)
                            if(i!=j && pos[j]!=perm[j] && cluster[pos[j]]!=cluster[perm[j]] && 
                            cluster[pos[i]]==cluster[perm[j]] && cluster[perm[i]]==cluster[pos[j]]){
                                flag=true;
                                swap(pos[i],pos[j]);
                                tm++;
                                i=j=n+1;
                            }
            }

            if(!flag){
                vector<vector<bool>> gr(ctr,vector<bool>(ctr,false));
                for(int i=0;i<n;i++){
                    if(pos[i]!=perm[i]&&cluster[pos[i]]!=cluster[perm[i]]){
                        gr[cluster[pos[i]]][cluster[perm[i]]]=true;
                    }
                }
                pair<int,int> ret=cycle_find(ctr,gr);
                if(ret.first!=-1 && ret.second!=-1){
                    int x=ret.first,y=ret.second;
                    for(int i=0;i<n;i++)
                        if(pos[i]!=perm[i]&&cluster[pos[i]]!=cluster[perm[i]]&&cluster[pos[i]]==x)
                            for(int j=0;j<n;j++)
                                if(i!=j && pos[j]!=perm[j] && cluster[pos[j]]!=cluster[perm[j]] && 
                                cluster[pos[j]]==cluster[perm[i]] && cluster[perm[j]]==y){
                                    flag=true;
                                    tm++;
                                    swap(pos[i],pos[j]);
                                    i=j=n+1;
                                }
                }
                else{
                    for(int i=0;i<n;i++)
                        if(pos[i]!=perm[i] && cluster[pos[i]]!=cluster[perm[i]])
                            for(int j=0;j<n;j++)
                                if(i!=j && pos[j]!=perm[j] && cluster[pos[j]]!=cluster[perm[j]] && cluster[pos[j]]==cluster[perm[i]]){
                                    flag=true;
                                    tm++;
                                    swap(pos[i],pos[j]);
                                    i=j=n+1;
                                }
                }
            }
            
            for(int i=0;i<n && !flag;i++) if(pos[i]!=perm[i]) flag=true;
        }

        cout<<tm<<"\n";
    }
    return 0;
}