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
    long long k;
    cin>>k;
    priority_queue<long long,vector<long long>,greater<long long>> pq;
    long long prod=1;
    for(int i=0;i<10;i++) pq.push(1ll);
    while(prod<k){
        long long tmp=pq.top();
        pq.pop();
        prod/=tmp;
        tmp++;
        prod*=tmp;
        pq.push(tmp);
    }
    string s="codeforces";
    int ind=0;
    while(!pq.empty()){
        for(int i=0;i<pq.top();i++){
            cout<<s[ind];
        }
        ind++;
        pq.pop();
    }
    cout<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}