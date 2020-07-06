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

int game(int n,vector<long long>& a){
    sort(full(a));
    for(int i=0;i<n;i++){
        if(i+1<n && a[i]==a[i+1]) return 0;
    }
    long long ans=0;
    for(int i=0;i<n;i++){
        ans+=a[i]-i;
        a[i]=i;
    }
    ans%=2;
    return ans+1;
}

void solve(){
    int n;cin>>n;
    vector<long long> a(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(full(a));
    bool flag=true;
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]){
            if(a[i-1]>0) a[i-1]--;
            flag=false;
            break;
        }
    }
    int ans=game(n,a);
    if(!flag) ans++;
    if(ans%2==0) cout<<"sjfnb\n";
    else cout<<"cslnb\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}