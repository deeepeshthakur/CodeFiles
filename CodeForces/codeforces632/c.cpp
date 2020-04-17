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
    vector<long long> a(n,0ll), dp(n,0ll);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    set<long long> st;
    st.insert(0ll);
    for(int i=0;i<n;i++){
        dp[i]=a[i];
        if(i>0){
            dp[i]+=dp[i-1];
        }
        st.insert(dp[i]);
    }

    long long ans=0;
    int min_dist=n;
    map<long long,int> ht;
    for(int i=n-1;i>=0;i--){
        if(ht.find(dp[i])==ht.end()){
            ht.insert({dp[i],i});
        }
        else{
            min_dist=min(min_dist,ht[dp[i]]);
            ht[dp[i]]=i;
        }
        if(i<n-1 && a[i+1]!=0){
            ans+=(min_dist-i-1);
        }
    }

    if(true){
        if(ht.find(0ll)!=ht.end()){
            min_dist=min(min_dist,ht[0ll]);
        }
        if(a[0]!=0){
            ans+=min_dist;
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