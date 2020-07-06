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

void print_vec(vector<int>& a, int n=-1){
    n=(n==-1?a.size():n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<(i<n-1?" ":"\n");
}

void solve(){
    int n;cin>>n;
    vector<int> a(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    int m;cin>>m;
    vector<int> b(m,0);
    for(int i=0;i<m;i++) cin>>b[i];
    sort(full(b));
    vector<int> vis(n,true);
    for(int i=0;i<n;i++){
        if(!binary_search(full(b),a[i])) vis[i]=false;
    }

    int ans=0;
    for(int i=0;i<n;i++){
        if(vis[i]){
            if(i==0 || !vis[i-1]){
                ans++;
            }
        }
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