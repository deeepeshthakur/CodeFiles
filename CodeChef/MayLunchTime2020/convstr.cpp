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
    cin>>n;
    string a,b;
    cin>>a>>b;
    vector<bool> vis(26,true);
    for(int i=0;i<n;i++) vis[int(b[i]-'a')]=false;
    for(int i=0;i<n;i++) vis[int(a[i]-'a')]=true;
    bool flag=true;
    for(int i=0;i<n;i++) if(a[i]<b[i]) flag=false;
    for(int i=0;i<26;i++) flag=(flag&&vis[i]);
    if(flag){
        vector<vector<int>> ans;
        for(auto i='z';i>='a';i--){
            vector<int> tmp;
            for(int j=0;j<n;j++){
                if(b[j]==i && a[j]!=b[j]) tmp.pb(j);
            }
            if(tmp.size()>0){
                for(int j=0;j<n;j++){
                    if(a[j]==i){
                        tmp.pb(j);
                        j=n+10;
                    }
                }
            }
            if(tmp.size()>0) ans.pb(tmp);
        }
        cout<<ans.size()<<"\n";
        for(int i=0;i<ans.size();i++){
            sort(full(ans[i]));
            cout<<ans[i].size()<<" ";
            for(int j=0;j<ans[i].size();j++) cout<<ans[i][j]<<(j+1<ans[i].size()?" ":"\n");
        }
    }   
    else{
        cout<<"-1\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}