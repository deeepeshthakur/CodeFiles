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

bool tf(int n,int k,vector<int>& a){
    int gd=__gcd(n,k);
    priority_queue<int> pq;
    for(int i=0;i<a.size();i++) pq.push(a[i]);
    int del=n/gd;
    for(int i=0;i<gd;i++){
        if(pq.top()>=del){
            int tmp=pq.top();
            pq.pop();
            pq.push(tmp-del);
        }
        else return false;
    }
    return true;
}

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(26,0);
    string s;
    cin>>s;
    for(int i=0;i<n;i++) a[int(s[i]-'a')]++;
    int ans=0;
    for(int i=n;i>=1;i--){
        if(tf(i,k,a)){
            ans=i;
            i=-1;
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