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

int gn(int i,vector<int>& next){
    if(i>=next.size()) return -1;
    if(next[i]==i || next[i]==-1) return next[i];
    return next[i]=gn(next[i],next);
}

void eq(int ind,int l, int r, int i, int val,vector<int>& st){
    if(l>r || i<l || r<i) return;
    if(l==r && l==i){
        st[ind]+=val;
        return;
    }
    eq(2*ind+1,l,(l+r)/2,i,val,st);
    eq(2*ind+2,(l+r)/2+1,r,i,val,st);
    int mid=(l+r)/2;
    st[ind]=0;
    if(l<=mid) st[ind]=max(st[ind],st[2*ind+1]);
    if(mid+1<=r) st[ind]=max(st[ind],st[2*ind+2]);
}

int sq(int ind,int l,int r, int s,int e, vector<int>& st){
    if(l>r || e<l || s>r) return 0;
    if(s<=l && r<=e) return st[ind];
    return max(sq(2*ind+1,l,(l+r)/2,s,e,st),sq(2*ind+2,(l+r)/2+1,r,s,e,st));

}

void solve(){
    int n;cin>>n;
    vector<pair<int,int>> p(n,{0,0});
    for(int i=0;i<n;i++) {
        cin>>p[i].first;p[i].second=i;
    }
    sort(full(p));
    int mx=1;
    vector<int> next(n,0),cnt(n,1);
    vector<int> st(5*n,0);
    for(int i=0;i<n;i++){
        eq(0,0,n-1,i,1,st);
    }
    for(int i=0;i<n;i++) next[i]=i;
    for(int i=0;i<n;i++){
        mx=sq(0,0,n-1,0,n-1,st);
        if(mx>cnt[p[i].second]){
            cout<<"No\n";
            return;
        }

        next[p[i].second]=gn(p[i].second+1,next);
        if(next[p[i].second]!=-1){
            eq(0,0,n-1,next[p[i].second],cnt[p[i].second],st);
            cnt[next[p[i].second]]+=cnt[p[i].second];
        }
        eq(0,0,n-1,p[i].second,-cnt[p[i].second],st);
    }
    cout<<"Yes\n";
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