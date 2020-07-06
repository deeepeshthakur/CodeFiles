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
    vector<bitset<25>> a(n,bitset<25>(0));
    for(int i=0;i<n;i++){
        long long x;
        cin>>x;
        a[i]=bitset<25>(x);
    }
    for(int i=0;i<25;i++){
        int ctr=0;
        for(int j=0;j<n;j++){
            if(a[j][i]==1){
                ctr++;
                a[j][i]=0;
            }
        }
        for(int j=0;j<ctr;j++){
            a[j][i]=1;
        }
    }
    unsigned long long ans=0;
    for(int i=0;i<n;i++){
        unsigned long long x=a[i].to_ullong();
        ans+=x*x;
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