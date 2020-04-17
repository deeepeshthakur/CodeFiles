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
int ind=0;

void solve(){
    long long n;cin>>n;
    vector<long long> a{1ll,2ll};
    while(a.back()<=n){
        a.pb((a[a.size()-1]+a[a.size()-2]));
    }
    int ctr=0;
    for(int i=0;i<a.size();i++) if(a[i]<=n) ctr=i;
    cout<<ctr<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}