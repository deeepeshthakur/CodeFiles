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

void print_vec(vector<long long>& a, int n=-1){
    n=(n==-1?a.size():n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<(i<n-1?" ":"\n");
}

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
                is_prime[i*j]=false;
                j++;
            }
        }
    }
    print_vec(primes,100);cout<<endl;
    long long n;cin>>n;
    long long ans=0;
    while(n>1){
        for(long long x=n;x>1;){
            if(check_prime(x,primes)){
                cout<<x<<"\n";
                n-=x;
                ans++;
                x=0;
            }
            else
                x--;
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