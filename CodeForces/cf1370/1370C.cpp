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

bool n_p2(long long n){
    if(n>2){
        long long x=4;
        while(x<=n){
            if(x==n) return true;
            x*=2;
        }
    }
    return false;
}

bool n_odd_prime(long long n){
    if(n>2 && n%2==0 && n%4!=0){
        long long x=n/2;
        for(int i=2;1ll*i*i<=x;i++){
            if(x%i==0) return false;
        }
        return true;
    }
    return false;
}

void solve(){
    long long n;
    cin>>n;
    if(n==1 || n_p2(n) || n_odd_prime(n)){
        cout<<"FastestFinger\n";
        return;
    }
    cout<<"Ashishgup\n";
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