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
const long long MOD=998244353ll;

bool compare_pr(const pair<pair<int,int>,long long>& a, const pair<pair<int,int>,long long>& b){
    return a.first.first<b.first.first || (a.first.first==b.first.first && a.first.second==b.first.second);
}

long long get_combin(int n, int m, vector<pair<int,int>>& intervals, vector<int>& x){
    
}

void solve(){
    int n,k,m;
    cin>>n>>k>>m;
    vector<pair<pair<int,int>,long long>> xl(m,{{0,0},0ll});
    for(int i=0;i<m;i++){
        cin>>xl[i].first.first>>xl[i].first.second>>xl[i].second;
    }

    sort(full(xl),compare_pr);
    vector<pair<int,int>> lr(m,{0,0});
    vector<long long> x(m,0ll);
    vector<int> x_bits(m,0); 
    for(int i=0;i<m;i++){
        lr[i].first=xl[i].first.first;
        lr[i].second=xl[i].first.second;
        x[i]=xl[i].second;
    }
    long long ans=1;
    for(int i=0;i<k;i++){
        for(int j=0;j<m;j++){
            x_bits[i]=x[i]%2;
            x[i]/=2;
        }
        ans=(ans*get_combin(n,m,lr,x_bits))%MOD;
    }

    cout<<ans<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}