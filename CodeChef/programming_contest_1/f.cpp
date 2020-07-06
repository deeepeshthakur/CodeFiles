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

struct query{
    int x,y,k;
};

query get_query(int x,int y,int k){
    query q;
    q.x=x-1;q.y=y-1;q.k=k;
    return q;
}

void print_vec(vector<long double>& a, int n=-1){
    n=(n==-1?a.size():n);
    for(int i=0;i<n;i++)
        cout<<fixed<<setprecision(8)<<a[i]<<(i<n-1?" ":"\n");
}

void solve(){
    int n;
    cin>>n;
    vector<vector<long double>> f(n,vector<long double>(n,0.0));
    for(int i=0;i<n;i++){
        vector<long long> d(n,0);
        for(int j=0;j<n;j++) cin>>d[j];
        long long sm=0;
        for(int j=0;j<n;j++) sm+=d[j];
        for(int j=0;j<n;j++) f[i][j]=(1.0*d[j]/sm);
    }
    int q,mk=0; cin>>q;
    vector<query> qu;
    for(int i=0;i<q;i++){
        int x,y,k;cin>>x>>y>>k;
        qu.pb(get_query(x,y,k));
        mk=max(mk,k);
    }
    vector<vector<vector<long double>>> dp(mk+1,vector<vector<long double>>(n,vector<long double>(n,0.0)));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) dp[1][i][j]=f[i][j];
    for(int i=0;i<n;i++) dp[0][i][i]=1.0;
    for(int i=2;i<dp.size();i++)
        for(int x=0;x<n;x++)
            for(int y=0;y<n;y++)
                for(int z=0;z<n;z++)
                    dp[i][x][y]+=dp[1][x][z]*dp[i-1][z][y];
    

    for(int i=0;i<q;i++){
        cout<<fixed<<setprecision(10)<<max((long double)(0.0),dp[qu[i].k][qu[i].x][qu[i].y])<<"\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}