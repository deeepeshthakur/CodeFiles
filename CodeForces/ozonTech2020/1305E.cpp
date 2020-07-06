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
    int n;
    long long m;
    cin>>n>>m;
    vector<long long> v;
    v.pb(1);v.pb(2);
    int del=-1;
    while(v.size()<n){
        if(m>0){
            if(m*2>=v.size()) { m-=v.size()/2; v.pb(v.back()+1); }
            else{
                v.pb(v.back()+v[v.size()-2*m]);
                m=0;
            }
        }else{
            if(del==-1) del=max(11ll,1ll*v.back() + (v.back()%2==0 ? 1 : 2));
            v.pb(v.back() + 2*del + (v.back()%2==0 ? 1 : 0));
        }
    }
    if(m>0) cout<<-1<<"\n";
    else{
        for(int i=0;i<n;i++) cout<<v[i]<<(i+1<n?" ":"\n");
    }

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}