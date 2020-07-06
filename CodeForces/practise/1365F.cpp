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

bool is_eq(pair<int,int> a, pair<int,int> b){
    if(a.first>a.second) swap(a.first,a.second);
    if(b.first>b.second) swap(b.first,b.second);
    return a.first==b.first && a.second==b.second;
}

bool is_possible(int ind, int n, vector<long long>& a, vector<long long>& b){
    for(int i=ind;i>=0;i--){
        int l=i,r=n-1-i;
        if(is_eq({a[l],a[r]},{b[ind],b[n-1-ind]})){
            if(l!=ind){
                swap(a[l],a[ind]);
                swap(a[r],a[n-1-ind]);
            }
            a[ind]=b[ind];
            a[n-1-ind]=b[n-1-ind];
            return true;
        }
    }
    return false;
}

void solve(){
    int n;
    cin>>n;
    vector<long long> a(n,0),b(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    bool flag=true;
    if(n%2==1){
        flag=(a[n/2]==b[n/2]);
    }
    for(int i=n/2-1;i>=0 && flag;i--){
        flag=is_possible(i,n,a,b);
    }
    if(flag) cout<<"Yes\n";
    else cout<<"No\n";
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