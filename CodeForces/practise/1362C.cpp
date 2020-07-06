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
    long long n;
    cin>>n;
    vector<pair<unsigned long long,unsigned long long>> dp;
    dp.pb({0,0});
    dp.pb({1,1});
    dp.pb({3,4});
    while(dp.back().first<n){
        unsigned long long x=(dp.back().first+1)*2ull-1,y=dp.back().second*2ull+dp.size();
        dp.pb({x,y});
    }
    if(n==1){
        cout<<1<<"\n";
        return;
    }
    if(n==2){
        cout<<3<<"\n";
        return;
    }
    unsigned long long ans=0;
    while(n>0){
        if(n==1){
            ans++;
            n=0;
        }
        else{
            if(n==2){
                ans+=3;
                n=0;
            }
            else{
                unsigned long long ind;
                for(int i=0;i<dp.size();i++)
                    if(n>=dp[i].first)
                        ind=i;
                n-=dp[ind].first;
                ans+=dp[ind].second;
                if(n>0) {
                    ans+=1ull*ind+1;
                    n--;
                }
            }
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