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

bool is_less(string& a, string& b){
    for(int i=0;i<a.size()&&i<b.size();i++){
        if(a[i]<b[i]){
            return true;
        }
        if(b[i]<a[i]){
            return false;
        }
    }
    return a.size()<=b.size();
}

long long gm(long long a, long long b){
    if(a ==-1 || b==-1){
        return a+b+1;
    }
    else{
        return min(a,b);
    }
}

void solve(){
    int n;
    cin>>n;
    vector<long long> c(n,0ll);
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    vector<string> svec(n);
    for(int i=0;i<n;i++){
        cin>>svec[i];
    }

    vector<pair<long long,long long>> dp(n,{0ll,0ll});
    vector<pair<string,string>> sv(n);
    for(int i=0;i<n;i++){
        sv[i].first=svec[i];
        sv[i].second=svec[i];
        for(int j=0;j<sv[i].second.size();j++){
            if(j<sv[i].second.size()-1-j){
                swap(sv[i].second[j],sv[i].second[sv[i].second.size()-1-j]);
            }
        }
    }

    // for(int i=0;i<n;i++){
    //     cout<<sv[i].first<<" "<<sv[i].second<<"\n";
    // }

    dp[n-1].second=c[n-1];
    for(int i=n-2;i>=0;i--){
        bool f1=is_less(sv[i].first,sv[i+1].first),f2=is_less(sv[i].first,sv[i+1].second);
        if(f1 || f2){
            if(f1&&f2){
                dp[i].first=gm(dp[i+1].first,dp[i+1].second);
            }
            else{
                dp[i].first=(f1?dp[i+1].first:dp[i+1].second);
            }
        }
        else{
            dp[i].first=-1;
        }
        
        f1=is_less(sv[i].second,sv[i+1].first);f2=is_less(sv[i].second,sv[i+1].second);
        if(f1 || f2){
            if(f1&&f2){
                dp[i].second=gm(dp[i+1].first,dp[i+1].second);
            }
            else{
                dp[i].second=(f1?dp[i+1].first:dp[i+1].second);
            }
        }
        else{
            dp[i].second=-1;
        }
        if(dp[i].second!=-1){
            dp[i].second+=c[i];
        }
        if(dp[i].first==-1 && dp[i].second==-1){
            cout<<"-1\n";
            return;
        }
    }
    cout<<gm(dp[0].first,dp[0].second)<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}