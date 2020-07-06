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
const long long MOD=998244353ll;

struct node{
    int l,r;
    bool prop,val;
    long long del,a,b,summ;
    node *left,*right;
};

void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<long long> a(n,0ll);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vector<long long> dp(n,0ll),d(m,0ll);
    for(int i=0;i<n;i++){
        dp[i]=a[i];
        if(i>0) dp[i]+=dp[i-1];
        dp
    }
    for(int i=0;i<m;i++){
        d[i]=
    }
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