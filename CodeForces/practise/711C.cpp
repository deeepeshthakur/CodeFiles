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

void print_vec(vector<long long>& a, int n=-1){
    n=(n==-1?a.size():n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<(i<n-1?" ":"\n");
}

void solve(){
    int n,m,k;cin>>n>>m>>k;
    vector<int> c(n,0);
    for(int i=0;i<n;i++) cin>>c[i];
    vector<vector<long long>> p(n,vector<long long>(m,0));
    long long inf=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>p[i][j];
            inf=max(inf,p[i][j]);
        }
    }

    if(m==1){
        if(k==1){
            long long ans=0;
            for(int i=0;i<n;i++){
                if(c[i]==0) ans+=p[i][0];
            }
            cout<<ans<<"\n";
        }
        else{
            cout<<-1<<"\n";
        }
        return;
    }

    vector<vector<vector<long long>>> dp(n,vector<vector<long long>>(m,vector<long long>(k,(inf*2+MOD)*n)));
    for(int i=0;i<m;i++){
        if(c[0]==0)
            dp[0][i][0]=min(dp[0][i][0],p[0][i]);
        if(c[0]!=0){
            dp[0][c[0]-1][0]=0;
        }
    }

    for(int z=0;z<k;z++){
        for(int x=1;x<n;x++){
            if(z>0){
                vector<pair<long long,int>> pq;
                for(int i=0;i<m;i++) pq.pb({dp[x-1][i][z-1],i}); sort(full(pq));
                pair<long long,int> a=pq[0],b=pq[1],aa; 

                for(int y=0;y<m;y++){
                    if((c[x-1]==0 || c[x-1]==y+1)&&(c[x]==0 || c[x]==y+1))
                        dp[x][y][z]=min(dp[x][y][z],dp[x-1][y][z]+((c[x]==0)?p[x][y]:0));

                    if(a.second==y) aa=b;
                    else aa=a;
                    if((c[x-1]==0 || c[x-1]!=y+1)&&(c[x]==0 || c[x]==y+1))
                        dp[x][y][z]=min(dp[x][y][z],aa.first+(c[x]==0?p[x][y]:0));
                }
            }
            else{
                for(int y=0;y<m;y++){
                    if(c[x]==y+1)
                        dp[x][y][z]=min(dp[x][y][z],dp[x-1][y][z]);
                    if(c[x]==0){
                        dp[x][y][z]=min(dp[x][y][z],p[x][y]+dp[x-1][y][z]);
                    }
                }
            }
        }
    }
    long long ans=(inf*2+MOD)*n;
    for(int j=0;j<m;j++){
        ans=min(ans,dp[n-1][j][k-1]);
    }

    if(ans >= inf*n+1) ans=-1;
    cout<<ans<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}