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

void solve(int test_case){
    int n,d;cin>>n>>d;
    vector<long long>a(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]*=2;
    }
    int ans=d-1;

    sort(full(a));
    int mtp=d,tuc=0;
    for(int i=0;i<n;i++){
        if(mtp>a[i]){
            mtp-=a[i];
            tuc+=a[i]-1;
        }
        else{
            tuc+=mtp;
            mtp=0;
        }
    }
    if(mtp==0) ans=min(ans,tuc);
    for(int i=0;i<n;i++){
        if(i==0 || a[i]!=a[i-1]){
            int cuts=0,pieces=0;
            for(int j=i;j<n && pieces<d;j++){
                if(a[j]%a[i]==0){
                    if(a[j]/a[i]<=(d-pieces)){
                        cuts+=(a[j]/a[i]-1);
                        pieces+=a[j]/a[i];
                    }
                    else{
                        cuts+=(d-pieces);
                        pieces=d;
                    }
                }
            }
            // cout<<i<<" "<<a[i]<<" "<<cuts<<" "<<pieces<<"\n";
            for(int j=i;j<n && pieces<d;j++){
                if(a[j]%a[i]!=0){
                    if(a[j]/a[i]<=(d-pieces)){
                        pieces+=a[j]/a[i];
                        cuts+=a[j]/a[i];
                    }
                    else{
                        cuts+=(d-pieces);
                        pieces=d;
                    }
                }
            }
            // cout<<i<<" "<<a[i]<<" "<<cuts<<" "<<pieces<<"\n";

            if(pieces==d && cuts<ans){ ans=cuts;}
        }
    }
    cout<<"Case #"<<test_case<<": "<<ans<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        solve(i);
    }
    return 0;
}