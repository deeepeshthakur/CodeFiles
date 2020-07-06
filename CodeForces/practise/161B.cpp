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

bool cmp(const vector<long long>& a,const vector<long long>& b){
    return a[0]<b[0] || (a[0]==b[0] && a[1]>b[1]);
}

void solve(){
    int n,k;cin>>n>>k;
    vector<vector<long long>> b(n,vector<long long>(3,0ll));
    for(int i=0;i<n;i++){
        cin>>b[i][1]>>b[i][0];
        b[i][2]=i+1;
    }
    sort(full(b),cmp);
    vector<vector<vector<long long>>> carts(k);
    for(int i=0;i<b.size();i++){
        if(i<k) carts[i].pb(b[i]);
        else carts[k-1].pb(b[i]);
    }
    long long tot=0,mn;
    for(int i=0;i<k;i++){
        bool is=(carts[i][0][0]==1);
        mn=carts[i][0][1]*10;
        for(int j=0;j<carts[i].size();j++){
            tot+=(carts[i][j][1]*10);
            mn=min(mn,carts[i][j][1]*10);
        }
        if(is){
            tot-=(mn/2);
        }
    }
    cout<<fixed<<setprecision(1)<<tot*0.1<<"\n";
    for(int i=0;i<k;i++){
        cout<<carts[i].size()<<" ";
        for(int j=0;j<carts[i].size();j++) cout<< carts[i][j][2]<<" ";
        cout<<"\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}