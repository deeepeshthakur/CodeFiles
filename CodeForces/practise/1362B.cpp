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

bool tf(int v, int n, vector<int>& a){
    vector<int> b(n,0);
    for(int i=0;i<n;i++) b[i]=(v^a[i]);
    // sort(full(a));
    sort(full(b));
    for(int i=0;i<n;i++) if(a[i]!=b[i]) return false;
    return true;
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> v;
    for(int i=1;i<n;i++) v.pb(a[i]^a[0]);
    sort(full(a));
    sort(full(v));
    for(int i=0;i<v.size();i++)
        if(v[i]>0 && tf(v[i],n,a)){
            cout<<v[i]<<"\n";
            return;
        }
    cout<<"-1\n";
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