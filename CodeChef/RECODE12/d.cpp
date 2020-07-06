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

bool comp(const pair<long long,int>& a,const pair<long long,int>& b){
    return a.first<b.first || (a.first==b.first && a.second<=b.second);
}

int gm(int val,vector<int>& a){
    if(a[0]>val) return a[0];
    int l=0,r=a.size()-1,mid;
    while(r-l>1){
        mid=(l+r)/2;
        if(a[mid]>val) r=mid;
        else l=mid;
    }
    if(a[l]>val) return a[l];
    return a[r];
}

void solve(){
    int n;cin>>n;
    vector<pair<long long,int>> a(n,{0,0});
    for(int i=0;i<n;i++) {cin>>a[i].first;a[i].second=i;}
    sort(full(a),comp);
    vector<long long> dist;
    vector<vector<int>> tr;
    for(int i=0;i<n;i++){
        if(i==0 || a[i].first!=a[i-1].first){
            dist.pb(a[i].first);
            tr.pb(vector<int>{a[i].second});
        }
        else{
            tr[tr.size()-1].pb(a[i].second);
        }
    }
    int curr=-1,ctr=0;
    for(int i=0;i<dist.size();i++){
        sort(full(tr[i]));
        if(curr==-1 || curr>tr[i].back()){
            ctr++;
            curr=tr[i][0];
        }
        else{
            curr=gm(curr,tr[i]);
        }
    }
    cout<<ctr<<"\n";
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