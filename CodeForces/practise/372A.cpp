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
    int n;cin>>n;
    vector<int> s(n,0);
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    sort(full(s));
    priority_queue<int> pq,pq1;
    for(int i=0;i<s.size();i++){
        if(i<s.size()/2)pq.push(s[i]);
        else pq1.push(s[i]);
    }
    int ctr=0;
    while(!pq.empty()){
        if(pq1.top()>=2*pq.top()){
            ctr++;
            pq1.pop();
        }
        pq.pop();
    }
    cout<<n-ctr<<"\n";    
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}