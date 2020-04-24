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

bool check_prime(long long n, vector<int>& primes){
    bool flag=true;
    for(int i=0;1ll*primes[i]*primes[i]<=n;i++){
        if(n%primes[i]==0){
            flag=false;
        }
    }
    return flag;
}

void solve(){
    long long n;cin>>n;
    vector<bool> is_prime(int(1e5),true);
    vector<int> primes;
    is_prime[0]=false;is_prime[1]=false;
    for(int i=0;i<is_prime.size();i++){
        if(is_prime[i]){
            primes.pb(i);
            int j=i;
            while(1ll*i*j<=is_prime.size()){
                is_prime[i*j]=false;
                j++;
            }
        }
    }

    if(check_prime(n,primes)){
        cout<<1<<"\n"<<n<<"\n";
        return;
    }

    if(check_prime(n-2,primes)){
        cout<<2<<"\n"<<2<<" "<<n-2<<"\n";
        return;
    }

    vector<pair<int,int>> dp(400,{0,0});
    for(int i=0;primes[i]<dp.size();i++){
        for(int j=i;primes[i]+primes[j]<dp.size();j++){
            dp[primes[i]+primes[j]]={primes[i],primes[j]};
        }
    }

    for(long long x=n-4;;x--){
        if(check_prime(x,primes)){
            cout<<3<<"\n";
            cout<<dp[n-x].first<<" "<<dp[n-x].second<<" "<<x<<"\n";
            return;
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}