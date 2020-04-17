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

void get_primes(vector<int>& a){
    int n=32000000;
    // vector<bool> is_prime(n+1,true);
    bitset<32000000+1> is_prime;
    is_prime[0]=1;
    is_prime[1]=1;
    for(int i=0;i<=n;i++){
        if(is_prime[i]==0){
            a.pb(i);
            int j=i;
            while(1ll*i*j<=1ll*n){
                is_prime[j*i]=1;
                j++;
            }
        }
    }
}

void solve(){
    long long d;
    cin>>d;
    vector<int> primes;
    get_primes(primes);
    // print_vec(primes,100);
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}