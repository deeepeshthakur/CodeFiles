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

long long pow_mod(long long a, long long b, long long mod){
    long long ans=1;
    a%=mod;
    while(b>0){
        if(b&1){
            ans*=a;
            ans%=mod;
        }
        b=b>>1;
        a=(a*a)%mod;
    }
    return ans;
}

void dfs(int ind, int parent,int &tin,vector<bool>& vis, vector<vector<int>>& gr, vector<int>& cur, vector<int>& lw, vector<int>& cnt){
    if(vis[ind]){
        tin++;
        vis[ind]=false;
        cur[ind]=tin;
        lw[ind]=tin;
        for(int i=0;i<gr[ind].size();i++){
            if(vis[gr[ind][i]]){
                dfs(gr[ind][i],ind,tin,vis,gr,cur,lw,cnt);
                cnt[ind]+=cnt[gr[ind][i]];
            }
        }

        for(int i=0;i<gr[ind].size();i++){
            if(gr[ind][i]!=parent)
                lw[ind]=min(lw[ind],lw[gr[ind][i]]);
        }

        cnt[ind]+=1;
    }
}

long long get_p(long long n, long long d){
    return (n*pow_mod(d,MOD-2,MOD))%MOD;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> gr(n);
    vector<pair<int,int>> edges(m,{0,0});
    for(int i=0;i<m;i++){
        cin>>edges[i].first>>edges[i].second;
        edges[i].first--;
        edges[i].second--;
        gr[edges[i].first].pb(edges[i].second);
        gr[edges[i].second].pb(edges[i].first);
    }

    int tin=-1;
    vector<int> lw(n,-1),cnt(n,0),cur(n,-1);
    vector<bool> vis(n,true);
    dfs(0,-1,tin,vis,gr,cur,lw,cnt);
    int p=0,q=0;
    for(int i=0;i<m;i++){
        if(cur[edges[i].first]>cur[edges[i].second]){
            swap(edges[i].first,edges[i].second);
        }
        if(lw[edges[i].second]>=cur[edges[i].second]){
            if(cnt[edges[i].second]%2==0 && n%2==0){
                p++;
            }
            else{
                q++;
            }
        }
    }

    if(p==0 && q==0){
        cout<<"0 0\n";
    }
    else{
        cout<<get_p(p*1ll,1ll*p+q)<<" "<<get_p(1ll*q,1ll*p+q)<<"\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}