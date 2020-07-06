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
long long MOD=1e9;

void solve(){
    int n;
    cin>>n;
    vector<long long> a(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    MOD*=MOD;
    long long ans=1;
    for(int i=0;i<n&&ans!=0;i++){
        if(a[i]!=0ll && ans!=0){
            if(ans!=-1){
                if(MOD/a[i]>=ans){
                    ans*=a[i];
                }
                else{
                    ans=-1;
                }
            }
        }
        else{
            ans=0;
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