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

void edit_query(int ind, int l, int r, int index, int val, vector<int>& st){
    if(l>r || index<l || r<index) return;
    if(l==r && index==r) {st[ind]+=val; return;}
    edit_query(2*ind+1,l,(l+r)/2,index,val,st);
    edit_query(2*ind+2,(l+r)/2+1,r,index,val,st);
    st[ind]=(r>=l?st[2*ind+1]:0)+(r>=l+1?st[2*ind+2]:0);
}

int search_query(int ind, int l, int r, int s, int e, vector<int>& st){
    if(l>r || e<l || s>r) return 0;
    if(s<=l && r<=e) return st[ind];
    return search_query(2*ind+1,l,(l+r)/2,s,e,st)+search_query(2*ind+2,(l+r)/2+1,r,s,e,st);
}

void solve(){
    int n,m;cin>>n>>m;
    vector<int> a(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> st(1000,0),ans(n,0),ctr(101,0),st1(1000,0);
    for(int i=0;i<n;i++){
        int l=0,r=100,mid,del;
        while(r-l>1){
            mid=(l+r)/2;
            if(a[i]+search_query(0,0,100,0,mid,st)<=m) l=mid;
            else r=mid;
        }
        if(search_query(0,0,100,0,r,st)+a[i]<=m) l=r;
        del=m-a[i]-search_query(0,0,100,0,l,st);
        ans[i]=i-search_query(0,0,100,0,l,st1);
        if(l<100){
            ans[i]-=(del/(l+1));
        }
        edit_query(0,0,100,a[i],a[i],st);
        edit_query(0,0,100,a[i],1,st1);
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}