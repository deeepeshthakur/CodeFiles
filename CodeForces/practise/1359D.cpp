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

// void eq(vector<int>& st, int ind, int l,int r,int index, int val){
//     if(l>r || index<l || index>r) return;
//     if(l==r && index==l){
//         st[ind]=val;
//         return;
//     }
//     eq(st,2*ind+1,l,(l+r)/2,index,val);
//     eq(st,2*ind+2,(l+r)/2+1,r,index,val);
//     st[ind]=max(st[2*ind+1],st[2*ind+2]);
// }

// int sq(vector<int>& st, int ind, int l, int r, int s,int e){
//     if(l>r || s>r || e<l) return -50;
//     if(s<=l && r<=e) return st[ind];
//     return  max(sq(st,2*ind+1,l,(l+r)/2,s,e),sq(st,2*ind+2,(l+r)/2+1,r,s,e));
// }

void fill_cd(vector<int>& b, vector<int>& c, vector<int>& d){
    int n=b.size();
    c[0]=b[0];
    for(int i=1;i<b.size();i++){
        c[i]=max(c[i-1],0)+b[i];
    }
    d[n-1]=b[n-1];
    for(int i=n-2;i>=0;i--){
        d[i]=max(d[i+1],0)+b[i];
    }
}

void solve(){
    int n,ans=0;
    cin>>n;
    vector<int> a(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<vector<int>> gr(31);
    for(int i=0;i<n;i++){
        gr[max(0,a[i])].pb(i);
    }
    vector<int> b(n,-10000000);
    for(int i=0;i<gr.size();i++){
        for(int j=0;j<gr[i].size();j++)
            b[gr[i][j]]=a[gr[i][j]];
        vector<int> c(n,0),d(n,0);
        fill_cd(b,c,d);
        for(int j=0;j<n;j++){
            if(a[j]==i){
                ans=max(ans,max((j>0?c[j-1]:0),0)+max((j+1<n?d[j+1]:0),0));
            }
        }
    }
    cout<<ans<<"\n";
    // vector<int> st(5*n+100,-50);
    // for(int i=0;i<n;i++)
    //     eq(st,0,0,n-1,i,a[i]);
    // for(int i=0;i<n;i++){
    //     int j=i;
    //     while(j+1<n && a[j+1]>=0)
    // }

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}