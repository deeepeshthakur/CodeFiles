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

bool cmp1(const pair<int,int>& a,const pair<int,int>& b){
    return a.first<b.first;
}

bool cmp2(const pair<int,int>& a,const pair<int,int>& b){
    return a.second<b.second || (a.second==b.second && a.first>b.first);
}

bool tf(int k, int n, vector<pair<int,int>>& dp){
    // cout<<k<<"\n";
    for(int i=0;i<=k;i++){
        int x=max(dp[i].first,dp[n-1+i-k].first),y=min(dp[i].second,dp[n-1+i-k].second);
        // cout<<x+1+n-y<<" ---- "<< k<<"\n";
        if(x+1+n-y<=k) return true;
    }
    return false;
}

void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> a(n,{0,0});
    for(int i=0;i<n;i++){
        cin>>a[i].second;
        a[i].first=i;
    }

    sort(full(a),cmp2);
    for(int i=0;i<n;i++){
        a[i].second=i;
    }
    sort(full(a),cmp1);
    vector<int> b(n,0);
    vector<pair<int,int>> dp(n,{-1,n});
    for(int i=0;i<n;i++) b[i]=a[i].second;
    set<int> s1,s2;
    s2.insert(n);
    for(int i=0;i<n;i++){
        dp[b[i]].second=*(s2.upper_bound(b[i]));
        s2.insert(b[i]);
    }
    s1.insert(1);
    for(int i=n-1;i>=0;i--){
        dp[b[i]].first=-(*(s1.upper_bound(-b[i])));
        s1.insert(-b[i]);
    }

    // for(int i=0;i<n;i++){
    //     cout<<dp[i].first<<" "<<dp[i].second<<"\n";
    // }
    int l=0,r=n-1,mid,ans=n;
    while(r-l>1){
        mid=(r+l)/2;
        if(tf(mid,n,dp)) r=mid;
        else l=mid;
    }
    if(tf(l,n,dp)) r=l;
    if(tf(r,n,dp)) ans=min(ans,r);
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