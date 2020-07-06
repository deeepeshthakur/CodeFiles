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

long long f(long long start, long long en, long long pos){
    if(pos%2==1) return (start+pos)/2;
    long long len=(en-start+1);
    if(len%2==0) return f(en+1,en+len/2,pos/2);
    pos/=2;
    if(pos==1) pos=len/2;
    else pos--;
    return f(en+2,en+1+len/2,pos);
}

void solve(){
    long long n,q,x;
    cin>>n>>q;
    for(int i=0;i<q;i++){
        cin>>x;
        cout<<f(1ll,n,x)<<"\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}