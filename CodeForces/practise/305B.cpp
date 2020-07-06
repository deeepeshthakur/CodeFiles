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

bool rec(long long p,long long q,queue<long long>& qu){
    // cout<<p<<" "<<q<<"\n";
    if(qu.empty()) return q==0;
    if(p==0 || q==0) return false;
    if(p/q >= qu.front()){
        p-=q*qu.front();
        qu.pop();
        return rec(q,p,qu);
    }
    return false;
}

void solve(){
    int n;
    long long p,q; cin>>p>>q;
    cin>>n;
    queue<long long> qu;
    while(n--){
        long long x;cin>>x;
        qu.push(x);
    }
    if(rec(p,q,qu)) cout<<"YES\n";
    else cout<<"NO\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}