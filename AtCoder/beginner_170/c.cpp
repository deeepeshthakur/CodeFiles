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
    int x,n;
    cin>>x>>n;
    vector<int> p(n,0);
    for(int i=0;i<n;i++) cin>>p[i];
    sort(full(p));
    int ans=-1000,ab=abs(-1000-x);
    for(int i=-110;i<=110;i++){
        if(!binary_search(full(p),i) && abs(x-i)<ab){
            ab=abs(x-i);
            ans=i;
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