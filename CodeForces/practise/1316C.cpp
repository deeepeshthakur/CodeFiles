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

int rec(int n,int m, int p, int l, int r, vector<int>& a, vector<int>& b){
    if(l<n && r<m){
        if(a[l]%p!=0 || b[r]%p!=0){
            if(a[l]%p!=0 && b[r]%p!=0) return l+r;
            if(a[l]%p!=0) for(int i=r;i<m;i++) if(b[i]%p!=0) return i+l;
            if(b[r]%p!=0) for(int i=l;i<n;i++) if(a[i]%p!=0) return i+r;
        }
        else{
            return rec(n,m,p,l+1,r+1,a,b);
        }
    }
    return -1;
}

void solve(){
    int n,m,p;cin>>n>>m>>p;
    vector<int> a(n,0),b(m,0);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int j=0;j<m;j++) cin>>b[j];
    int ans=rec(n,m,p,0,0,a,b);
    cout<<ans<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}