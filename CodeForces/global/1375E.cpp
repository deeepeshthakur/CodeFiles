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
    vector<int> a(n,0),b(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) b[i]=a[i];
    sort(full(b));
    vector<pair<int,int>> ans;
    for(int i=0;i<n;i++){
        if(b[i]!=a[i]){
            int curr=i;
            for(int j=i;j<n;j++){
                if(b[i]==a[j]){
                    curr=j;
                    j=n+10;
                }
            }
            if(curr==i){
                cout<<"-1\n";
                return;
            }else
            {
                ans.pb({i+1,curr+1});
                swap(a[i],a[curr]);
            }
        }
    }
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++) cout<<ans[i].first<<" "<<ans[i].second<<"\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t=1;
    while(t--){
        solve();
    }
    return 0;
}