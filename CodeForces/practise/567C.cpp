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
    long long n,k,ans=0;
    cin>>n>>k;
    vector<long long> a(n,0ll);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    map<long long,long long> ht1,ht2;
    for(int i=n-1;i>=0;i--){
        if(ht2.find(a[i]*k)!=ht2.end()){
            ans+=ht2.find(a[i]*k)->second;
        }
        if(ht1.find(a[i]*k)!=ht1.end()){
            if(ht2.find(a[i])!=ht2.end()){
                ht2.find(a[i])->second+=(ht1.find(a[i]*k)->second);
            }
            else{
                ht2.insert({a[i],ht1.find(a[i]*k)->second});
            }
        }
        if(ht1.find(a[i])!=ht1.end()){
            ht1.find(a[i])->second++;
        }
        else{
            ht1.insert({a[i],1ll});
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