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

long long f(int n,int m, int x,bitset<12>& bs, vector<long long>& c, vector<vector<long long>>& a){
    vector<long long> ans(m,0);
    long long cst=0;
    for(int i=0;i<n;i++){
        if(bs[i]==1){
            for(int j=0;j<m;j++){
                ans[j]+=a[i][j];
            }
            cst+=c[i];
        }
    }
    for(int i=0;i<m;i++){
        if(ans[i]<x){
            return -1;
        }
    }
    return cst;
}

void solve(){
    int n,m,x;cin>>n>>m>>x;
    vector<long long> c(n,0ll);
    vector<vector<long long>> a(n,vector<long long>(m,0ll));
    for(int i=0;i<n;i++){
        cin>>c[i];
        for(int j=0;j<m;j++) cin>>a[i][j];
    }
    long long ans=-1;
    for(int i=1;i<=(1<<12);i++){
        bitset<12> bs(i);
        long long ret=f(n,m,x,bs,c,a);
        if(ans==-1 || (ret>=0 && ret<ans)) ans=ret;
    }
    cout<<ans<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}