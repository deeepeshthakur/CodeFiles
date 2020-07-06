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
    int n,m;cin>>n>>m;
    
    vector<vector<long long>> a(n,vector<long long>(m,0ll)), b(n,vector<long long>(m,0ll)), c(n,vector<long long>(m,0ll)), d(n,vector<long long>(m,0ll)), e(n,vector<long long>(m,0ll));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>a[i][j];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) b[i][j]=a[i][j]+max(i>0?b[i-1][j]:0ll,j>0?b[i][j-1]:0ll);
    for(int i=n-1;i>=0;i--) for(int j=0;j<m;j++) c[i][j]=a[i][j]+max(i+1<n?c[i+1][j]:0ll,j>0?c[i][j-1]:0ll);
    for(int i=n-1;i>=0;i--) for(int j=m-1;j>=0;j--) d[i][j]=a[i][j]+max(i+1<n?d[i+1][j]:0ll,j+1<m?d[i][j+1]:0ll);
    for(int i=0;i<n;i++) for(int j=m-1;j>=0;j--) e[i][j]=a[i][j]+max(i>0?e[i-1][j]:0ll,j+1<m?e[i][j+1]:0ll);

    long long ans=0,prev=0;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++){
        if(i>0 && j>0 && i+1<n && j+1<m){
            ans=max(ans,b[i-1][j]+c[i][j-1]+d[i+1][j]+e[i][j+1]);
            ans=max(ans,c[i+1][j]+b[i][j-1]+e[i-1][j]+d[i][j+1]);
        }
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