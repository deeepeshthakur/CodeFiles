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

bitset<63> gq(int a, int b, int x, int y){
    unsigned long long ans;
    vector<int> xx;
    for(int i=a;i<=b;i++) xx.pb(i);
    for(int i=x;i<=y;i++) xx.pb(i);
    cout<<xx.size()<<" ";
    for(int i=0;i<xx.size();i++) cout<<xx[i]<<(i+1<xx.size()?" ":"");
    cout<<endl;
    cin>>ans;
    return bitset<63>(ans);
}

vector<int> f(int n, vector<int>& s1, vector<int>& e1, vector<int>& s2, vector<int>& e2, vector<int>& q){
    
}

void solve(){
    int n;
    cin>>n;
    vector<bitset<63>> a(n,bitset<63>(0ll));
    vector<int> s1,e1,s2,e2;
    vector<bitset<63>> qu;
    s1.pb(1);
    e1.pb(n/2);
    s2.pb(e1.back()+1);
    e2.pb(n);
    for(int i=0;i<13;i++){
        qu.pb(gq(s1.back(),e1.back(),s2.back(),e2.back()));
        if(i+1<13){
        int s=s1.back(),e=e1.back();
        s1.pb(s);
        e1.pb((s+e)/2);
        s=s1.back();
        e=e1.back();
        s1.pb(s);
        e1.pb((s+e)/2);
        }
    }
    for(int i=0;i<63;i++){
        vector<int> q(qu.size());
        for(int j=0;j<q.size();j++) q[j]=qu[j][i];
        vector<int> ans= f(n,s1,e1,s2,e2,q);
        for(int j=0;j<n;j++) a[j][i]=ans[j];
    }
    cout<<"! ";
    for(int i=0;i<n;i++) cout<<a[i].to_ulong()<<(i+1<n" ":"");
    cout<<endl;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}