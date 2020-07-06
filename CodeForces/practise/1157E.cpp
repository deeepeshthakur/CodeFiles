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

int gp(int i,vector<int>& p){
    if(i<0) return -1;
    if(p[i]==i) return p[i];
    return p[i]=gp(p[i],p);
}

int gn(int i,vector<int>& n){
    if(i>=n.size()) return n.size()+1;
    if(n[i]==i) return n[i];
    return n[i]=gn(n[i],n);
}

void solve(){
    int n;cin>>n;
    vector<int> a(n,0),b(n,0),c(n,0),prev(n,-1),next(n,n+1);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0;i<n;i++) c[b[i]]++;
    for(int i=0;i<n;i++){
        if(c[i]>0) prev[i]=i;
        else prev[i]=gp(i-1,prev);        
    }
    for(int i=n-1;i>=0;i--){
        if(c[i]>0) next[i]=i;
        else next[i]=gn(i+1,next);
    }

    for(int i=0;i<n;i++){
        int p=gp((n-a[i])%n,prev),q=gn((n-a[i])%n,next);
        if(p<0) p=gp(n-1,prev);
        if(q>=n) q=gn(0,next);
        if((p+a[i])%n<=(q+a[i])%n){
            b[i]=(p+a[i])%n;
            c[p]--;
            if(c[p]<=0){
                prev[p]=gp(p-1,prev);
                next[p]=gn(p+1,next);
            }
        }
        else{
            b[i]=(a[i]+q)%n;
            c[q]--;
            if(c[q]<=0){
                prev[q]=gp(q-1,prev);
                next[q]=gn(q+1,next);
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<b[i]<<" ";
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