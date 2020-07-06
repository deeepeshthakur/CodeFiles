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

void solve(){
    int n;
    cin>>n;
    vector<int> a(n,0),b(n,0),pos(n,0),posb(n,0),ans(n+10,0);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) a[i]--;
    for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0;i<n;i++) b[i]--;
    for(int i=0;i<n;i++) pos[a[i]]=i;
    for(int i=0;i<n;i++) posb[b[i]]=pos[b[i]]-i;
    for(int i=0;i<n;i++) if(posb[i]<0) posb[i]+=n;
    for(int i=0;i<n;i++) ans[posb[i]]++;
    int fin=0;
    for(int i=0;i<ans.size();i++) fin=max(fin,ans[i]);
    cout<<fin<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}