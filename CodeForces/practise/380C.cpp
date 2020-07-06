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
    int l,r,mx;
    vector<node*> c;
};

node* gn(){
    node *a = new node;
    a->l=a->r=a->mx=0;
    a->c.resize(0);
    return a;
}

void make_tree(node *st, vector<int>& prs){
    for(int i=st->l+1;i<st->r;i++){
        if(prs[i]>1){   
            node *a= gn();
            a->l=i;a->r=prs[i];a->mx=0;
            make_tree(a,prs);
            i=a->r+1;
            st->c.push_back(a);
        }
    }
    for(int i=0;i<st->c.size();i++){
        node* curr=st->c[i];
        st->mx=max(st->mx,curr->mx);
        if(curr->r-curr->l+1==curr->mx){
            int j=i+1;
            
        }        
    }
}

void solve(){
    string s;
    cin>>s;
    int n=s.size();

    int q;
    cin>>q;
    vector<pair<int,int>> queries(q,{0,0});
    for(int i=0;i<q;i++) cin>>queries[i].first>>queries[i].second;

    stack<int> curr;
    vector<int> prs(n+1,-1);
    for(int i=0;i<n;i++){
        if(s[i]=='(') curr.push(i);
        else{
            if(!curr.empty()){
                int st=curr.top()+1, en=i+1;
                prs[st]=i+1;
                prs[en]=0;
            }
        }
    }

    node *st = gn();
    st->l=0;st->r=n+1;st->mx=0;
    make_tree(st,prs);
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}