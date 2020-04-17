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

void bfs(int ind, int k, int n, int un, queue<int>& q, vector<int>& a, vector<bool>& vis){
    if(vis[ind]){
        vis[ind]=false;
        int j;
        for(int i=0;i*k+ind<n;i++){
            j=i*k+ind;
            a[j]=un;
            if(vis[(n-1-j)%k]){
                q.push((n-1-j)%k);
            }
        }
    }
}

void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;


    queue<int> qu;
    int un=0;
    vector<int> a(n,-1);
    vector<bool> vis(k,true);
    for(int i=0;i<k;i++){
        if(vis[i]){
            qu.push(i);
            // vis[i]=false;
            while(!qu.empty()){
                bfs(qu.front(),k,n,un,qu,a,vis);
                qu.pop();
            }   
            un++;
        }
    }
    
    vector<vector<int>> dp(un,vector<int>(26,0));
    for(int i=0;i<n;i++){
        dp[a[i]][int(s[i]-'a')]++;
    }

    int ans=0;
    for(int i=0;i<un;i++){
        int tmp=0,sm=0;
        for(int j=0;j<26;j++){
            sm+=dp[i][j];
            tmp=max(tmp,dp[i][j]);
        }
        ans+=(sm-tmp);
    }
    cout<<ans<<"\n";
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