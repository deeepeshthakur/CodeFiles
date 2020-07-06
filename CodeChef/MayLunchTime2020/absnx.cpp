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


long long f(int n, vector<long long> a){
    long long ans=0;
    stack<pair<long long,int>> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && st.top().first>a[i]){
            st.pop();
        }
        int tmp=1;
        if(!st.empty()){
            ans+=st.top().second;
            tmp+=st.top().second;
        }
        st.push({a[i],tmp});
    }
    while(!st.empty()) st.pop();
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top().first>a[i]){
            st.pop();
        }
        int tmp=1;
        if(!st.empty()){
            ans+=st.top().second;
            tmp+=st.top().second;
        }
        st.push({a[i],tmp});
    }
    ans+=n;
    long long mx=0;
    for(int i=0;i<n;i++) mx=max(a[i],mx);
    long long ctr=0;
    for(int i=0;i<n;i++){
        if(a[i]==mx){
            ctr++;
        }
        else{
            ans-=(ctr*ctr)-(ctr*ctr+ctr)/2;
            ctr=0;
        }
    }
    return ans-(ctr*ctr)+(ctr*ctr+ctr)/2;
}

void solve(){
    int n;
    cin>>n;
    vector<long long> a(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    if(n<=2000){
        int ans=0;
        for(int i=0;i<n;i++){
            long long mx=a[i],mn=a[i];
            for(int j=i;j<n;j++){
                mx=max(mx,a[j]);
                mn=min(mn,a[j]);
                if(abs(mx-mn)==abs(a[i]-a[j])) ans++;
            }
        }
        cout<<ans<<"\n";
    }
    if(true){
        long long ans=0;
        ans+=f(n,a);
        long long mx=0;
        for(int i=0;i<n;i++) mx=max(a[i],mx);
        for(int i=0;i<n;i++){
            a[i]=mx-a[i];
        }
        ans+=f(n,a);
        cout<<"Here  "<<ans<<"\n";
    }


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