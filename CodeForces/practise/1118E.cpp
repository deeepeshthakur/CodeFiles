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
    int n,k;
    cin>>n>>k;
    if(1ll*k*k-k<n) cout<<"NO\n";
    else{
        vector<pair<int,int>> ans;
        int ctr=1;
        while(ans.size()<n && ctr<=k){
            int x=ctr,y=1;
            while(x>0 && y>0 && x<=k && y<=k && ans.size()<n){
                if(x!=y) ans.pb({x,y});
                x--;y++;
            }
            ctr++;
        }
        ctr=2;
        while(ans.size()<n && ctr<=k){
            int x=k,y=ctr;
            while(x>0 && y>0 && x<=k && y<=k && ans.size()<n){
                if(x!=y) ans.pb({x,y});
                x--;y++;
            }
            ctr++;
        }
        cout<<"YES\n";
        for(int i=0;i<ans.size();i++) cout<<ans[i].first<<" "<<ans[i].second<<"\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}