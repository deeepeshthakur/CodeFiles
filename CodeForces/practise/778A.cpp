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

bool dpf(int i,int j, vector<char>& s, string& p){
    if(i>=s.size()) return (j>=p.size());
    if(s[i]==p[j]) return(dpf(i+1,j+1,s,p));
    return dpf(i+1,j,s,p);
}

bool tf(int mid, int n, string& t, string& p, vector<int>& a){
    vector<bool> vis(n,true);
    vector<char> s;
    for(int i=0;i<mid;i++) vis[a[i]-1]=false;
    for(int i=0;i<n;i++) if(vis[i]) s.pb(t[i]);
    if(p.size()>s.size()) return false;
    return dpf(0,0,s,p);
}

void solve(){
    string t,p;
    int n;
    cin>>t>>p;
    n=t.size();
    vector<int> a(n,0);
    for(int i=0;i<n;i++) cin>>a[i];

    int l=0,r=n,mid;
    while(r-l>1){
        mid=(l+r)/2;
        if(tf(mid,n,t,p,a)) l=mid;
        else r=mid;
    }
    if(tf(r,n,t,p,a)) l=r;
    cout<<l<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}