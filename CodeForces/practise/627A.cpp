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

void print_vec(vector<int>& a, int n=-1){
    n=(n==-1?a.size():n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<(i<n-1?" ":"\n");
}

void solve(){
    long long s,x,del,del1;
    cin>>s>>x;
    del1=del=s-x;
    long long ans=0;
    if(del%2==0 && del>=0){
        // cout<<del<<" "<<x<<"\n";
        vector<int> a(45,0);
        for(int i=0;i<45;i++){
            if(x%2==1) a[i]=1;
            x/=2;
        }

        bool flag=true;
        // print_vec(a);
        del/=2;
        for(int i=0;i<45;i++){
            if(del%2==1 && a[i]!=0) flag=false;
            del/=2;
        }
        if(flag){
            long long ctr=0;
            for(int i=0;i<45;i++) if(a[i]==1) ctr++;
            // cout<<ctr<<"\n";
            ans=(1ll<<ctr)-(del1==0?2:0);
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