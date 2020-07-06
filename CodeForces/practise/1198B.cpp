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
    int l,r;
    long long val,to_prop;
    bool prop;
    node *left,*right;
};

node* get_new_node(){
    node *a=new node;
    a->l=a->r=0;
    a->val=a->to_prop=-1ll;
    a->prop=false;
    a->left=a->right=NULL;
    return a;
}

node* make_tree(int l,int r, vector<long long>& a){
    if(l>r) return NULL;
    if(l==r){
        node *ans=get_new_node();
        ans->l=l;ans->r=r;
        ans->val=a[l];
        return ans;
    }

    node *ans=get_new_node();
    ans->l=l;
    ans->r=r;
    ans->left=make_tree(l,(l+r)/2,a);
    ans->right=make_tree((l+r)/2+1,r,a);
    ans->val=-1;
    if(ans->left && ans->left->val>=0) if(ans->val==-1 || (ans->val)>(ans->left->val)) ans->val=ans->left->val;
    if(ans->right && ans->right->val>=0) if(ans->val==-1 || ans->val>ans->right->val) ans->val=ans->right->val;
    return ans;
}

void eq(node *st,int l,int r, long long val, bool lazy=true){

    if(st->r<l || st->l>r) return;

    if(st->r==st->l && st->l>=l && st->r<=r){
        if(st->prop){
            st->val=max(st->val,st->to_prop);
            st->prop=false;
            st->to_prop=-1;
        }
        if(lazy) st->val=max(st->val,val);
        else st->val=val;
        return;
    }

    if(l<=st->l && st->r<=r){
        if(lazy){
            st->prop=true;
            st->to_prop=max(st->to_prop,val);
            return;
        }
        else{
            if(st->prop){
                st->prop=false;
                st->val=max(st->val,st->to_prop);
                if(st->left){
                    st->left->prop=true;
                    st->left->to_prop=max(st->to_prop,st->left->to_prop);
                }
                if(st->right){
                    st->right->prop=true;
                    st->right->to_prop=max(st->to_prop,st->right->to_prop);
                }
                st->to_prop=-1;
            }
            if(st->left) eq(st->left,l,r,val,lazy);
            if(st->right) eq(st->right,l,r,val,lazy);
            st->val=-1;
            if(st->left && st->left->val>=0) if(st->val==-1 || (st->val)>(st->left->val)) st->val=st->left->val;
            if(st->right && st->right->val>=0) if(st->val==-1 || st->val>st->right->val) st->val=st->right->val;
            return;
        }
    }

    if(st->prop){
        st->prop=false;
        st->val=max(st->val,st->to_prop);
        if(st->left){
            st->left->prop=true;
            st->left->to_prop=max(st->to_prop,st->left->to_prop);
        }
        if(st->right){
            st->right->prop=true;
            st->right->to_prop=max(st->to_prop,st->right->to_prop);
        }
        st->to_prop=-1;
    }

    if(st->left) eq(st->left,l,r,val,lazy);
    if(st->right) eq(st->right,l,r,val,lazy);
    st->val=-1;
    if(st->left && st->left->val>=0) if(st->val==-1 || (st->val)>(st->left->val)) st->val=st->left->val;
    if(st->right && st->right->val>=0) if(st->val==-1 || st->val>st->right->val) st->val=st->right->val;
    return;
}

long long sq(node *st,int ind){
    if(st->l>ind || ind>st->r) return 0ll;
    if(st->l==st->r && st->r==ind){
        if(st->prop){
            st->prop=false;
            st->val=max(st->val,st->to_prop);
            st->to_prop=-1;
        }
        return st->val;
    }

    if(st->prop){
        st->prop=false;
        st->val=max(st->val,st->to_prop);
        if(st->left){
            st->left->prop=true;
            st->left->to_prop=max(st->left->to_prop,st->to_prop);

        }
        if(st->right){
            st->right->prop=true;
            st->right->to_prop=max(st->right->to_prop,st->to_prop);
        }
        st->to_prop=-1;
    }
    long long ret=0;
    if(st->left) ret=max(ret,sq(st->left,ind));
    if(st->right) ret=max(ret,sq(st->right,ind));
    return ret;
}

void solve(){
    int n;cin>>n;
    vector<long long> a(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    node *st=make_tree(0,n-1,a);
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int qn,p;cin>>qn;
        long long x;
        if(qn==1){
            cin>>p>>x;
            eq(st,p-1,p-1,x,false);
        }
        else{
            cin>>x;
            eq(st,0,n-1,x,true);
        }
    }
    for(int i=0;i<n;i++){
        cout<<sq(st,i)<<" ";
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