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
    priority_queue<int> pq;
    map<int,int> ht;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x;cin>>x;
            pq.push(x);
            if(ht.find(x)==ht.end()){
                ht.insert({x,0});
            }
        }
    }
    vector<int>ans;
    int curr;
    while(!pq.empty()){
        curr=pq.top();pq.pop();
        if(ht[curr]==0){
            for(int i=0;i<ans.size();i++){
                ht[__gcd(ans[i],curr)]+=2;
            }
            ans.pb(curr);
        }
        else{
            ht[curr]--;
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
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