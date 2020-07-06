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
    map<long long,pair<int,int>> ht;
    for(long long m=1000;m*m-1<=MOD;m++){
        for(long long n=m;n*n-(n/m)*(n/m)<=MOD;n++){
            cout<<m<<" "<<n<<"  "<<ht.size()<<"\n";
            long long xx=n*n-(n/m)*(n/m);
            if(ht.find(xx)==ht.end()) ht.insert({xx,{n,m}});
        }
    }
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        long long x;
        cin>>x;
        if(ht.find(x)!=ht.end()){
            auto itr=ht[x];
            cout<<itr.first<<" "<<itr.second<<"\n";
        }
        else cout<<"-1\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}