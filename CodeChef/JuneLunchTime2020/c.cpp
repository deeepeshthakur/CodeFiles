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
const long double eps=1e-20;
const long long MOD=1e9+7;

bool cmp(const pair<pair<long double,long double>,int>& a, const pair<pair<long double,long double>,int>& b){
    return a.first.first>b.first.first || (a.first.first==b.first.first && a.first.second>b.first.second);
}

queue<int> f(vector<long double> a,vector<long double> b){
    int n=a.size();
    vector<pair<pair<long double,long double>,int>> s;
    for(int i=0;i<n;i++) s.pb({{a[i],b[i]},i});
    sort(full(s),cmp);
    queue<int> q;
    for(int i=0;i<n;i++) q.push(s[i].second);
    return q;
}

void solve(){
    int n;
    cin>>n;
    vector<long double> a(n,0),b(n,0),g(n,0);
    for(int i=0;i<n;i++){
        cin>>g[i]>>a[i]>>b[i];
        a[i]=g[i]/a[i];
        b[i]=g[i]/b[i];
    }
    auto x=f(a,b);
    auto y=f(b,a);
    long double ansx=0,ansy=0;
    while(!x.empty() && !y.empty()){
        while(!x.empty() && (g[x.front()]<=eps)) x.pop();
        while(!y.empty() && (g[y.front()]<=eps)) y.pop();

        if(!x.empty() && !y.empty()){
            int xx=x.front(),yy=y.front();
            if(xx==yy){
                long double t=g[xx]/(a[xx]+b[xx]);
                ansx+=t*a[xx];
                ansy+=t*b[xx];
                g[xx]==0;
                x.pop();
                y.pop();
            }
            else{
                long double tx=g[xx]/a[xx],ty=g[yy]/b[yy];
                tx=min(tx,ty);
                ansx+=a[xx]*tx;
                ansy+=b[yy]*tx;
                g[xx]-=a[xx]*tx;
                g[yy]-=b[yy]*tx;
                if(g[xx]<=eps) x.pop();
                if(g[yy]<=eps) y.pop();
            }
        }
    }
    cout<<fixed<<setprecision(10)<<ansx<<" "<<ansy<<"\n";
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