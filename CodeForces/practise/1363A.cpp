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
    int n,k;
    cin>>n>>k;
    int o=0,e=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x%2==1) o++;
        else e++;
    }
    for(int i=0;i<=k;i++){
        if(i%2==1 && i<=o && k-i<=e){
            cout<<"Yes\n";
            return;
        }
    }
    cout<<"No\n";
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