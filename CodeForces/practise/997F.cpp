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
    int n;
    cin>>n;
    vector<long long> a(n,0ll);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    map<long long,int> ht;
    for(int i=n-1;i>=0;i--){
        int len=1+(ht.find(a[i]+1)!=ht.end()?ht.find(a[i]+1)->second:0);
        if(ht.find(a[i])!=ht.end()){
            ht.find(a[i])->second=max(ht.find(a[i])->second,len);
        }
        else{
            ht.insert({a[i],len});
        }
    }
    // cout<<"HERE"<<endl;
    auto mx_itr=ht.begin();
    for(auto itr=ht.begin();itr!=ht.end();itr++){
        if(mx_itr->second < itr->second){
            mx_itr=itr;
        }
    }
    long long curr=mx_itr->first;
    cout<<mx_itr->second<<"\n";
    for(int i=0;i<n;i++){
        if(a[i]==curr){
            cout<<i+1<<" ";
            curr++;
        }
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