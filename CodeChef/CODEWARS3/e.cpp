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
    int a,b,c,d;
    bool prop;
    long long val,del;
    node *north,*south,*east,*west;
};

node* get_node(){
    node *a=new node;
    a->a=a->b=a->c=a->d=0;
    a->prop=false;
    a->val=a->del=0;
    a->north=a->south=a->east=a->west=NULL;
}

node* make_tree(int a, int b, int c,int d, vector<vector<long long>>& g){
    if(a>c || b>d) return NULL;
    node *st=get_node();
    if(a==c && b==d){
        st->a=st->c=a;
        st->b=st->d=b;
        st->val=g[a][b];
        st->north=st->south=st->east=st->west=NULL;
        return st;
    }
    st->a=a;st->b=b;st->c=c;st->d=d;
    int c1=(a+c)/2,c2=(b+d)/2;
    st->north=make_tree(a,b,c1,c2,g);
    st->east=make_tree(a,c2+1,c1,d,g);
    st->south=make_tree(c1+1,c2+1,c,d,g);
    st->west=make_tree(c1+1,b,c,c2,g);
    st->val=0;
    if(st->north) st->val+=st->north->val;
    if(st->east) st->val+=st->east->val;
    if(st->south) st->val+=st->south->val;
    if(st->west) st->val+=st->west->val;
    return st;
}

void eq(node *st, int a,int c,int b, int d, long long del){
    if(st==NULL) return;
    if(st->a>c || st->c<a || st->b>d || st->d<b) return;
    if(a<=st->a && st->c<=c && b<=st->b && st->d<=d){
        st->prop=true;
        st->del+=del;
        return;
    }

    if(st->del!=0){
        if(st->north) st->north->del+=st->del;
        if(st->south) st->south->del+=st->del;
        if(st->west) st->west->del+=st->del;
        if(st->east) st->east->del+=st->del;
        st->del=0;
    }
    
    if(st->north) eq(st->north,a,c,b,d,del);
    if(st->east) eq(st->east,a,c,b,d,del);
    if(st->south) eq(st->south,a,c,b,d,del);
    if(st->west) eq(st->west,a,c,b,d,del);
}

void redo_tree(node *st){
    if(st!=NULL){
        if(st->a<st->c || st->b<st->d){
            st->val=0;
        }
        else{
            st->val+=st->del;
            st->del=0;
        }

        if(st->del!=0){
            if(st->north) {st->north->del+=st->del; redo_tree(st->north);}
            if(st->south) {st->south->del+=st->del;redo_tree(st->south);}
            if(st->west) {st->west->del+=st->del;redo_tree(st->west);}
            if(st->east) {st->east->del+=st->del;redo_tree(st->east);}
            st->del=0;
        }

        if(st->north) redo_tree(st->north);
        if(st->south) redo_tree(st->south);
        if(st->west) redo_tree(st->west);
        if(st->east) redo_tree(st->east);

        if(st->north) st->val+=st->north->val;
        if(st->south) st->val+=st->south->val;
        if(st->west) st->val+=st->west->val;
        if(st->east) st->val+=st->east->val;
    }
}

long long sq(node *st, int a,int c,int b, int d){
    if(st==NULL || st->a>c || st->c<a || st->d<b || st->b>d) return 0ll;
    if(a<=st->a && c>=st->c && b<=st->b && d>=st->d) {
        return st->val;
    }
    return sq(st->north,a,c,b,d)+sq(st->east,a,c,b,d)+sq(st->west,a,c,b,d)+sq(st->south,a,c,b,d);
}

void solve(){
    int n,m,u,q;
    cin>>n>>m>>u>>q;
    vector<vector<long long>> grid(n,vector<long long>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    node *st=make_tree(0,0,n-1,m-1,grid);
    for(int i=0;i<u;i++){
        long long del;
        int a,b,c,d;
        cin>>del>>a>>b>>c>>d;
        eq(st,min(a,n-1),min(c,n-1),min(b,m-1),min(d,m-1),del);
    }

    redo_tree(st);
    for(int i=0;i<q;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        cout<<sq(st,min(a,n-1),min(c,n-1),min(b,m-1),min(d,m-1))<<"\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}