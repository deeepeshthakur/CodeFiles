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
    if(l>r || index<l || r<index)
        return;
    if(l==r){
        st[ind]+=val;
    }
    else{
         st[ind]=int(1e6);
        if(l<=(l+r)/2){
            edit_query(2*ind+1,l,(l+r)/2,index,val,st);
            st[ind]=min(st[ind],st[2*ind+1]);
        }

        if((l+r)/2+1<=r){
            edit_query(2*ind+2,(l+r)/2+1,r,index,val,st);
            st[ind]=min(st[ind],st[2*ind+2]);
        }
    }
}

int search_query(int ind, int l, int r, int s, int e, vector<int>& st){
    if(e<l || r<s)
        return int(1e6);
    if(s<=l&&r<=e)
        return st[ind];
    return min(search_query(2*ind+1,l,(l+r)/2,s,e,st),search_query(2*ind+2,(l+r)/2+1,r,s,e,st));
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n,0);
    
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]--;
    }
    
    vector<int> st(4*n,n);
    for(int i=0;i<n;i++){
        edit_query(0,0,n-1,i,i,st);
        if(a[i]>=0 && a[i]<n){
            edit_query(0,0,n-1,(n+i-a[i])%n,-1,st);
        }
    }

    int q,x,b;
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>x>>b;
        x--;b--;
        if(a[x]>=0&&a[x]<n){
            edit_query(0,0,n-1,(n+x-a[x])%n,+1,st);
        }
        a[x]=b;
        if(a[x]>=0&&a[x]<n){
            edit_query(0,0,n-1,(n+x-a[x])%n,-1,st);
        }
        cout<<min(n,search_query(0,0,n-1,0,n-1,st))<<"\n";
    }
    
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}