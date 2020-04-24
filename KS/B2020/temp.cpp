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

bool check_prime(long long a,vector<long long>& b){
    if(binary_search(full(b),a))
        return true;
    for(int i=0;i<b.size();i++) if(a%b[i]==0) return false;
    return true;
}

void solve(){
    vector<bool> is_prime(int(1e5),true);
    is_prime[0]=false;
    is_prime[1]=false;
    vector<long long> primes;
    for(int i=0;i<is_prime.size();i++){
        if(is_prime[i]){
            primes.pb(i*1ll);
            int j=i;
            while(1ll*j*i<is_prime.size()){
                is_prime[i]=false;
                j++;
            }
        }
    }
    long long n;cin>>n;
    long long ans=0;
    while(n>0){
        for(long long x=n;x>=0;x--){
            if(check_prime(x,primes)){
                // ans.pb(x);
                n-=x;ans++;
                break;
            }
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