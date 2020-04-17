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
    vector<int> a(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> dl(n,1),dr(n,1);
    for(int i=0;i<n;i++){
        if(i && a[i-1]<a[i]){
            dl[i]+=dl[i-1];
        }
    }
    for(int i=n-2;i>=0;i--){
        if(a[i]<a[i+1]){
            dr[i]+=dr[i+1];
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
        ans=max(ans,dl[i]);
    for(int i=0;i<n;i++){
        if(i>0 && i<n-1){
            if(a[i-1]+2<=a[i+1]){
                ans=max(ans,dl[i-1]+dr[i+1]+1);
            }
            else{
                ans=max(ans,max(dl[i-1]+1,dr[i+1]+1));
            }
        }
        else{
            ans=max(ans,(i>0?(1+dl[i-1]):0));
            ans=max(ans,(i<n-1?(1+dr[i+1]):0));
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