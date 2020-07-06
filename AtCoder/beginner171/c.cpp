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

string gf(int ctr,long long n){
    string s(ctr,'a');
    for(int i=s.size()-1;i>=0;i--){
        s[i]=char('a'+n%26);
        n/=26;
    }
    return s;
}

void solve(){
    long long n;
    cin>>n;
    int ctr=1;
    long long mul=1,tot=0;
    while(tot+mul*26<n){
        mul*=26;
        tot+=mul;
        ctr++;
    }
    n-=tot;
    cout<<gf(ctr,n-1)<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}