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

struct cmp{
    bool operator() (const pair<int,int>& a, const pair<int,int>& b){
        return min(a.first,a.second)<min(b.first,b.second);
    }
};

void solve(){
    int n;
    cin>>n;
    vector<long long> a(n,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>, cmp> pq;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(rfull(a));
    long long ans=0;
    pq.push({a[0],a[0]});
    for(int i=1;i<n;i++){
        auto tp=pq.top();pq.pop();
        ans+=min(tp.first,tp.second);
        pq.push({a[i],tp.first});
        pq.push({a[i],tp.second});
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