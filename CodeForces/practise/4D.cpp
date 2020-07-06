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

bool cmp(const pair<pair<int,int>,int>& a, const pair<pair<int,int>,int>& b){
    return a.first<b.first;
}

void solve(){
    int n,w,h;
    cin>>n>>w>>h;
    vector<pair<pair<int,int>,int>> a(n,{{0,0},0});
    for(int i=0;i<n;i++) {cin>>a[i].first.first>>a[i].first.second; a[i].second=i+1;}
    sort(full(a),cmp);

    vector<pair<int,int>> dp(n,{1,-1});
    for(int i=n-1;i>=0;i--){
        int x=1,y=-1;
        for(int j=i+1;j<n;j++){
            if(a[i].first.first<a[j].first.first && a[i].first.second < a[j].first.second){
                if(x<dp[j].first+1){
                    x=dp[j].first+1;
                    y=j;
                }
            }
        }
        dp[i]={x,y};
    }
    int x=0,y=-1;
    for(int i=0;i<n;i++) if(w<a[i].first.first && h<a[i].first.second && x<dp[i].first){
        x=dp[i].first;
        y=i;
    }
    cout<<x<<"\n";
    while(y>=0){
        cout<<a[y].second;
        y=dp[y].second;
        if(y>=0) cout<<" ";
        else cout<<"\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}