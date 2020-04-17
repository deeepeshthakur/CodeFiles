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
    int n,q;
    cin>>n>>q;
    vector<int> a(n,0),b(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(full(a));
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        b[l-1]++;
        if(r<n){
            b[r]--;
        }
    }
    int curr=0;
    for(int i=0;i<n;i++){
        curr+=b[i];
        b[i]=curr;
    }
    sort(full(b));
    long long ans=0;
    for(int i=0;i<n;i++){
        ans+=1ll*b[i]*a[i];
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