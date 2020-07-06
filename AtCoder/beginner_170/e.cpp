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

int mnf(int a,int b){
    if(a>b) swap(a,b);
    if(a==-1) return b;
    return a;
}

void eq(int ind, vector<int>& st, int l,int r, int index, int val){
    if(l>r || index<l ||index>r) return;
    if(l==r && index==r){
        st[ind]=val;
        return;
    }

    eq(2*ind+1,st,l,(l+r)/2,index,val);
    eq(2*ind+2,st,(l+r)/2+1,r,index,val);
    st[ind]=mnf(st[2*ind+1],st[2*ind+2]);
}

int sq(int ind, vector<int>& st, int s,int e, int l, int r){
    if(l>r || s>r || e<l) return -1;
    if(s<=l && r<=e) return st[ind];
    return mnf(sq(2*ind+1,st,s,e,l,(l+r)/2),sq(2*ind+2,st,s,e,(l+r)/2+1,r));
}

void solve(){
    int n,q,kg=2*int(1e5)+1;
    cin>>n>>q;
    vector<pair<int,int>> inp(n,{0,0});
    vector<multiset<int>> sets(kg);
    for(int i=0;i<kg;i++){
        sets[i].insert(-1);
    }
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        inp[i]={a,b};
        sets[b].insert(a);
    }

    vector<int> st(1048576,-1);
    for(int i=0;i<kg;i++){
        eq(0,st,0,kg-1,i,*(sets[i].rbegin()));
    }

    for(int i=0;i<q;i++){
        int c,d,val;
        cin>>c>>d;
        c--;
        val=inp[c].first;
        sets[inp[c].second].erase(val);
        val=*(sets[inp[c].second].rbegin());
        eq(0,st,0,kg-1,inp[c].second,val);
        val=inp[c].first;
        inp[c].second=d;
        sets[d].insert(val);
        val=*(sets[d].rbegin());
        eq(0,st,0,kg-1,d,val);
        cout<<sq(0,st,0,kg-1,0,kg-1)<<"\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}