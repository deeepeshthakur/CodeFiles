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
    long long x,d;
    cin>>x>>d;
    vector<long long> ans;
    int i=0;
    long long curr=1;
    while(x){
        if(x%2){
            for(int j=0;j<i;j++) ans.pb(curr);
            ans.pb(curr+d);
            curr+=2ll*d;
        }
        i++;
        x/=2;
    }
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<(i+1<ans.size()?" ":"\n");
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}