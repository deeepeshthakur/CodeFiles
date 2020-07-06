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
    vector<long long> a(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    map<long long,int> ht;
    long long ans=0;
    for(int i=n-1;i>=0;i--){
        long long curr=i+1+a[i];
        if(ht.find(curr)!=ht.end()){
            ans+=ht[curr];
        }

        curr=i+1-a[i];
        if(ht.find(curr)!=ht.end()){
            ht[curr]++;
        }
        else{
            ht.insert({curr,1});
        }
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