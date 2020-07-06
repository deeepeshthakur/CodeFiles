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

int p_q(int k1,int k2,vector<int>& a, vector<int>& b){
    cout<<k1<<" "<<k2<<" ";
    for(int i=0;i<a.size();i++) cout<<a[i]<<" ";
    for(int i=0;i<b.size();i++) cout<<b[i]<<" ";
    cout<<endl;
    int ret;
    cin>>ret;
    return ret;
}

int fq(int k1,int k2,int a, int b){
    vector<int> aa,bb;
    for(int i=0;i<k1;i++) aa.pb(a+i);
    for(int i=0;i<k2;i++) bb.pb(b+i);
    return p_q(k1,k2,aa,bb);
}

int get_f(int a,int b,int dist){
    if(a==b) return a;
    int mid=(a+b)/2;
    if(fq(1,mid-a+1,1,a)==dist) return get_f(a,mid,dist);
    return get_f(mid+1,b,dist);
}

void solve(){
    int n;
    cin>>n;
    int dist=fq(1,n-1,1,2);
    int ind=get_f(2,n,dist);
    vector<int> a,b;
    for(int i=1;i<n+1;i++) if(i!=ind) b.pb(i);
    a.pb(ind);
    ind=p_q(a.size(),b.size(),a,b);
    cout<<-1<<" "<<ind<<endl;
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