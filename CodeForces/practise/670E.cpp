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
    int val;
    node *left,*right;
};

node* gn(){
    node *a= new node;
    a->val;
    a->left=a->right=NULL;
    return a;
}

void solve(){
    int n,m,p;
    cin>>n>>m>>p;p--;
    string s;
    cin>>s;
    node *qu=gn(),*nxt=qu;
    for(int i=0;i<n;i++){
        nxt->val=(s[i]=='('?1:-1);
        if(i+1<n) {
            nxt->right=gn();
            nxt->right->left=nxt;
            nxt=nxt->right;
        }
    }
    nxt=qu;
    while(p--)
        nxt=nxt->right;
    
    string cmd;
    cin>>cmd;
    for(int i=0;i<m;i++){
        if(cmd[i]=='L') nxt=nxt->left;
        if(cmd[i]=='R') nxt=nxt->right;
        if(cmd[i]=='D'){
            if(nxt->val==1){
                node *a=nxt,*b=nxt->right;
                int sm=1;
                while(sm>0){
                    sm+=b->val;
                    b=b->right;
                }
                a=a->left;
                // b=b->right;
                if(a) a->right=b;
                if(b) b->left=a;

                if(b) nxt=b;
                else nxt=a;
            }
            else{
                node *a=nxt->left,*b=nxt;
                int sm=-1;
                while(sm<0){
                    sm+=a->val;
                    a=a->left;
                }
                // a=a->left;
                b=b->right;
                if(a) a->right=b;
                if(b) b->left=a;
                
                if(b) nxt=b;
                else nxt=a;
            }
        }
    }

    while(nxt->left) nxt=nxt->left;
    while(nxt){
        cout<<(nxt->val==1?'(':')');
        nxt=nxt->right;
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