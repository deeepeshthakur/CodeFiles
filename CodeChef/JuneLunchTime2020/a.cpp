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

bool cmp(const pair<int,long long>& a, const pair<int,long long>& b){
    return a.second>b.second || (a.second==b.second && a.first<b.first);
}

void solve(){
    int n,k;
    cin>>n>>k;
    vector<long long> dp(35,0ll);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        bitset<35> a(x);
        for(int j=0;j<35;j++){
            if(a[j]==1) dp[j]++;
        }
    }
    vector<pair<int,long long>> st;
    for(int i=0;i<35;i++) st.pb({i,dp[i]*(1ll<<i)});
    sort(full(st),cmp);
    bitset<35> ans(0);
    for(int i=0;i<k;i++) ans[st[i].first]=1;
    cout<<ans.to_ullong()<<"\n";
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