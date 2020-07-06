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
    long long n;cin>>n;
    vector<bool> is_prime(int(2e5),true);
    vector<int> prime;
    is_prime[0]=is_prime[1]=false;
    for(int i=0;i<is_prime.size();i++){
        if(is_prime[i]){
            prime.pb(i);
            int j=i;
            while(1ll*i*j<is_prime.size()){
                is_prime[i*j]=false;
                j++;
            }
        }
    }
    long long mx=-1;
    for(int i=0;i<prime.size() && mx==-1;i++){
        if(n%prime[i]==0) mx=prime[i];
    }
    if(mx==-1) mx=n;
    long long ans=0;
    if(mx!=2 && n/mx!=1){
        ans=1+(n-mx)/2;
    }
    else{
        ans=n/mx;
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