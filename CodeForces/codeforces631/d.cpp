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

void print_vec(vector<long long>& a, int n=-1){
    n=(n==-1?a.size():n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<(i<n-1?" ":"\n");
}

void solve(){
    long long d,m;
    cin>>d>>m;
    long long ans=1;
    long long an=0,t=1;
    while(t<=d){
        t*=2ll;
        an++;
    }
    vector<long long> com(an,1ll);

    for(int i=1;i<an;i++){
        com[i]=(com[i-1]*2ll)%m;
    }
    if(an>0){
        com[an-1]=(d+m-com[an-1]+1)%m;
    }
    for(int i=0;i<an;i++){
        ans*=(com[i]+1);
        ans%=m;
    }
    cout<<(ans+m-1)%m<<"\n";





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