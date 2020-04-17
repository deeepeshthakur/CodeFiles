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

void print_vec(vector<int>& a, int n=-1){
    n=(n==-1?a.size():n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<(i<n-1?" ":"\n");
}

void edit_query(int ind, int l, int r, int index, int val,vector<int>& st){
    if(l>r || index<l || r<index)
        return;
    if(l==r && index==l){
        st[ind]+=val;
        return;
    }
    int mid=(l+r)/2;
    st[ind]=2;
    if(l<=mid){
        edit_query(2*ind+1,l,mid,index,val,st);
        st[ind]=min(st[ind],st[2*ind+1]);
    }
    if(mid+1<=r){
        edit_query(2*ind+2,mid+1,r,index,val,st);
        st[ind]=min(st[ind],st[2*ind+2]);
    }
}

int search_query(int ind, int l, int r, int s, int e, vector<int>& st){
    if(l>r || e<l || r<s){
        return 10;
    }

    if(s<=l && r<=e){
        return st[ind];
    }

    int x=min(search_query(2*ind+1,l,(l+r)/2,s,e,st),search_query(2*ind+2,(l+r)/2+1,r,s,e,st));
    return x;
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int ans=0,max_ele=0;
    vector<pair<int,int>> ans_vec;
    set<int> dis_ele;
    vector<int> st(5*n+10,0);
    for(int i=0;i<n;i++){
        edit_query(0,0,n-1,a[i]-1,1,st);
    }

    for(int i=0;i<n;i++){
        max_ele=max(max_ele,a[i]);
        dis_ele.insert(a[i]);
        edit_query(0,0,n-1,a[i]-1,-1,st);
        int x=search_query(0,0,n-1,0,n-i-2,st);
        if(max_ele==dis_ele.size() && max_ele==i+1 && x==1){
            ans++;
            ans_vec.pb({i+1,n-i-1});
        }
    }
    cout<<ans<<"\n";
    for(int i=0;i<ans_vec.size();i++){
        cout<<ans_vec[i].first<<" "<<ans_vec[i].second<<"\n";
    }
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