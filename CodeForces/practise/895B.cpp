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

struct node{
    long long l,r;
    int val;
    node *left,*right;
};

node* gn(long long ll=0, long long rr=0,long long vv=0){
    node *a=new node;
    a->val=vv;
    a->l=ll;a->r=rr;
    a->left=a->right=NULL;
    return a;
}

void make_tree(node *st, long long val){
    if(!st || st->l>val || st->r<val || (st->l)>(st->r)) return;
    if(st->l==st->r && st->r==val){
        st->val++;
        return;
    }
    if(!st->left) st->left=gn(st->l,(st->r+st->l)/2,0);
    if(!st->right) st->right=gn((st->r+st->l)/2+1,st->r,0);
    make_tree(st->left,val);
    make_tree(st->right,val);
    st->val=0;
    if(st->left) st->val+=st->left->val;
    if(st->right) st->val+=st->right->val;
}

int sq(node* st,long long s, long long e){
    if(!st || e<st->l || s>st->r || st->l>st->r) return 0;
    if(s<=st->l && st->r<=e) return st->val;
    return (st->left?sq(st->left,s,e):0)+(st->right?sq(st->right,s,e):0);
}

void solve(){
    int n;
    long long x,k;
    cin>>n>>x>>k;
    vector<long long> a(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    node *st=gn(1ll,int(1e9),0);
    for(int i=0;i<n;i++) make_tree(st,a[i]);
    long long ans=0,l,r,xl,xr;
    for(int i=n-1;i>=0;i--){
        if(a[i]%x==0) xl=a[i]/x;
        else xl=a[i]/x+1;
        xr=xl+k-1;
        if(MOD/x>=xr){
            l=xr*x;
            r=l+x-1;
            ans+=1ll*sq(st,max(a[i],l),r);
        }
    }
    st=gn(1ll,int(1e9),0);
    cout<<ans<<"\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}