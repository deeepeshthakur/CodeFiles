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
    int l,r,val,mx,mn;
    node *left,*right;
};

node* getn(){
    node *a=new node;
    a->l=a->r=a->val=a->mx=a->mn=0;
    a->right=a->left=NULL;
    return a;
}

void make_tree(node *st, int l,int r, vector<int>& pos){
    if(st && l<=r){
        if(l==r){
            st->l=l;
            st->r=r;
            st->val=0;
            st->mn=st->mx=pos[l];
            st->right=st->left=NULL;
            return;
        }
        else{
            st->left=getn();
            st->right=getn();
            make_tree(st->left,l,(l+r)/2,pos);
            make_tree(st->right,(l+r)/2+1,r,pos);
            st->l=l;
            st->r=r;
            st->val=st->left->val+st->right->val+(st->left->mx<st->right->mn?0:1);
            st->mn=st->left->mn;
            st->mx=st->right->mx;
            return;
        }
    }
}

void eq(node* st,int ind, int val){
    if(st && st->l<=ind && st->r>=ind){
        if(st->l==st->r && st->r==ind){
            st->mn=val;
            st->mx=val;
            return;
        }
        else{
            eq(st->left,ind,val);
            eq(st->right,ind,val);
            st->val=0;
            st->mn=-1;
            st->mx=-1;
            if(st->left){
                st->val+=st->left->val;
                st->mn=st->left->mn;
                st->mx=st->left->mx;;
            }
            if(st->right){
                st->val+=st->right->val;
                st->mx=st->right->mx;
            }
            if(st->right&&st->left){
                st->val+=(st->left->mx<st->right->mn?0:1);
            }
            return;
        }
    }
}

int sq(node *st, int l, int r){
    if(st==NULL || l>st->r || r<st->l) return -1;
    if(st->l>=l && st->r<=r) return st->val;
    int lv=sq(st->left,l,r),rv=sq(st->right,l,r);
    if(lv!=-1 && rv!=-1) return lv+rv+((st->left&&st->right&&(st->left->mx>=st->right->mn))?1:0);
    return (lv!=-1?lv:rv);
}

void solve(){
    int n;
    cin>>n;
    vector<int> pos(n,0),a(n,0);
    for(int i=0;i<n;i++){
        int x;cin>>x;
        pos[x-1]=i;
        a[i]=x-1;
    }
    node *st=getn();
    // vector<pair<int,int>> st(5*n,{n,0});
    make_tree(st,0,n-1,pos);

    int q;
    cin>>q;
    int ax,ay;
    for(int i=0;i<q;i++){
        int p,x,y;cin>>p>>x>>y;
        x--;y--;
        if(p==1){
            cout<<1+sq(st,x,y)<<"\n";
        }
        else{
            ax=a[x];ay=a[y];
            swap(pos[ax],pos[ay]);
            eq(st,ax,pos[ax]);
            eq(st,ay,pos[ay]);
            a[x]=ay;
            a[y]=ax;
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}