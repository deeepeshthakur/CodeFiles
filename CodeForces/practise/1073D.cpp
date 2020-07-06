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

void eq(int ind,int l,int r,int index, long long val, vector<long long>& st){
    if(l>r || index<l || index>r) return;
    if(l==r && index==r){
        st[ind]=val;
        return;
    }
    eq(2*ind+1,l,(l+r)/2,index,val,st);
    eq(2*ind+2,(l+r)/2+1,r,index,val,st);
    st[ind]=0;
    if(l<r) st[ind]+=(st[2*ind+1]+st[2*ind+2]);
}

long long sq(int ind, int l, int r, int s, int e, vector<long long>& st){
    if(l>r || e<l || r<s) return 0ll;
    if(s<=l && r<=e) return st[ind];
    return sq(2*ind+1,l,(l+r)/2,s,e,st)+sq(2*ind+2,(l+r)/2+1,r,s,e,st);
}

void solve(){
    int n;long long t;
    cin>>n>>t;
    vector<long long> a(n,0ll);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vector<pair<long long,int>> sorted_a(n,{0ll,0});
    vector<long long> dp_sorted(n,0ll),dp(n,0ll);
    for(int i=0;i<n;i++) sorted_a[i]={a[i],i};
    sort(full(sorted_a));
    for(int i=0;i<n;i++){
        dp[i]=a[i];
        dp_sorted[i]=sorted_a[i].first;
        if(i>0){
            dp[i]+=dp[i-1];
            dp_sorted[i]+=dp_sorted[i-1];
        }
    }

    vector<long long> st(5*n,0ll);
    for(int i=0;i<n;i++) eq(0,0,n-1,i,a[i],st);
    long long ans=0;
    for(int i=n-1;i>=0;i--){
        long long g=t/dp_sorted[i];
        if(g*dp_sorted[i] + sq(0,0,n-1,0,sorted_a[i].second,st)<=t){
            g++;
        }
        ans+=g;
        t-=sorted_a[i].first*g;
        eq(0,0,n-1,sorted_a[i].second,0ll,st);
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