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
    int n,s=int(1e6);cin>>n;
    vector<int> a(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<pair<int,int>> b(s/2,{0,0});
    for(int i=0;i<b.size();i++) b[i]={i+1,s-i};
    for(int i=0;i<n;i++){
        if(a[i]<s+1-a[i]){
            b[a[i]-1].first=-1;
        }
        else{
            b[s-a[i]].second=-1;
        }
    }
    vector<int> ans;
    int ctr=0;
    for(int i=0;i<b.size();i++){
        if(b[i].first==-1 || b[i].second==-1){
            if(b[i].first==-1 && b[i].second==-1) ctr++;
            else ans.pb(b[i].first+b[i].second+1);
        }
    }
    for(int i=0;i<b.size()&&ctr>0;i++)
        if(b[i].first>=0 && b[i].second>=0){
            ans.pb(b[i].first);
            ans.pb(b[i].second);
            ctr--;
        }
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    cout<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}