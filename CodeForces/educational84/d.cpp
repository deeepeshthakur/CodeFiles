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

int get_min2(int l, vector<int>& a){
    
}

int get_min(int l, vector<pair<int,int>>& a){
    int ans=l;
    sort(full(a));
    for(int i=0;i<l;i++){
        vector<int> tmp;
        int j=i;
        while(j<l && a[j].first==a[i].first){
            tmp.pb(a[j].second);
            j++;
        }
        i=j;
        ans=get_min2(l,tmp);
    }
    return ans;
}

void solve(){
    int n;
    cin>>n;
    vector<int> p(n,0),c(n,0);
    for(int i=0;i<n;i++){
        cin>>p[i];
        p[i]--;
    }
    for(int i=0;i<n;i++){
        cin>>c[i];
    }

    // vector<vector<int>> paths(n);
    int ans=n;
    vector<bool> vis(n,true);
    for(int i=0;i<n;i++){
        if(vis[i]){
            vector<int> pth;
            pth.pb(i);
            vis[i]=false;
            while(p[pth[pth.size()-1]]!=i){
                int tmp=p[pth[pth.size()-1]];
                pth.pb(tmp);
                vis[tmp]=false;
            }
            if(pth.size()<ans){
                ans=pth.size();
            }
            vector<pair<int,int>> tmp_arr(pth.size());
            for(int j=0;j<pth.size();j++){
                tmp_arr[j].first=c[pth[j]];
                tmp_arr[j].second=j;
            }
            int tmp_ans=get_min(pth.size(),tmp_arr);
            if(ans>tmp_ans){
                ans=tmp_ans;
            }
        }
    }

    cout<<ans<<"\n";
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