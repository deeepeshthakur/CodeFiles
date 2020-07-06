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

void solve(){
    int n,q;
    cin>>n;
    vector<long long> a(int(1e5)+1,0);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[x]++;
    }
    long long sm=0;
    for(int i=0;i<a.size();i++) sm+=(a[i]*i);
    cin>>q;
    for(int i=0;i<q;i++){
        int b,c;
        cin>>b>>c;
        long long del=a[b]*(c-b);
        a[c]+=a[b];
        a[b]=0;
        sm+=del;
        cout<<sm<<"\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}