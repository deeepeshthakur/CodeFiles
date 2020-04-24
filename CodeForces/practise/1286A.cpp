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
    int odd=n/2+n%2,even=n-odd;
    vector<int> a(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    if(n==1){
        cout<<0<<"\n";
        return;
    }
    for(int i=0;i<n;i++){
        if(a[i]!=0)
        if(a[i]%2) odd--;
        else even--;
    }
    if(odd+even==n){
        cout<<1<<"\n";
        return;
    }
    int ans=0;
    priority_queue<int,vector<int>,greater<int>> pq,pq1;
    for(int i=0;i<n;i++){
        if(a[i]!=0){
            if(i+1<n && a[i+1]!=0) ans+=(a[i]+a[i+1])%2;
            if(i+1<n && a[i+1]==0){
                int j=i+1;
                while(j<n && a[j]==0) j++;
                if(j<n){
                    if((a[i]+a[j])%2==0){
                        if(a[i]%2==0)
                            pq.push(j-i-1);
                        else pq1.push(j-i-1);
                    }
                    else ans+=1;
                }
            }
        }
    }
    // cout<<ans<<"\n";
    while(!pq.empty()){
        if(pq.top()<=even) even-=pq.top();
        else ans+=2;
        pq.pop();
    }
    while(!pq1.empty()){
        if(pq1.top()<=odd) odd-=pq1.top();
        else ans+=2;
        pq1.pop();
    }
    int j=0;
    while(j<n && a[j]==0) j++;
    if(a[j]%2){
        if(j>odd) ans++;
        else odd-=j;
    }
    else{
        if(j>even) ans++;
        else even-=j;
    }
    j=n-1;
    while(j>-1 && a[j]==0) j--;
    if(a[j]%2){
        if(n-j-1>odd) ans++;
    }
    else{
        if(n-j-1>even) ans++;
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