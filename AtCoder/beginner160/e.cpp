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
    int x,y,a,b,c;
    cin>>x>>y>>a>>b>>c;
    vector<long long> p(a,0ll),q(b,0ll),r(c,0ll);
    for(int i=0;i<a;i++)
        cin>>p[i];
    for(int i=0;i<b;i++)
        cin>>q[i];
    for(int i=0;i<c;i++)
        cin>>r[i];
    
    sort(rfull(p));
    sort(rfull(q));
    sort(rfull(r));
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<x;i++)
        pq.push(p[i]);
    for(int i=0;i<y;i++)
        pq.push(q[i]);
    for(int i=0;i<c;i++){
        if(pq.top()<r[i]){
            pq.pop();
            pq.push(r[i]);
        }
    }

    long long ans=0;
    while(!pq.empty()){
        ans+=pq.top();
        pq.pop();
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