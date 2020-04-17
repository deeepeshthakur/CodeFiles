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
    vector<bool> is_prime(n+1,true);is_prime[0]=false;is_prime[1]=false;
    vector<int> primes;
    for(int i=0;i<=n;i++){
        if(is_prime[i]){
            int j=2;
            while(1ll*j*i<is_prime.size()){
                is_prime[i*j]=false;
                j++;
            }
        }
    }
    for(int i=0;i<is_prime.size();i++){
        if(is_prime[i]){
            primes.pb(i);
        }
    }
    vector<bool> ans(n+1,true);
    vector<int> a(n,n);
    for(int i=n-1;i>=0;i++){
        int l=1,r=n,mid;
        while(r-l>1){
            mid=(l+r)/2;
            bool flag=false;
            if(ans[mid]){
                int j=0;
                while(!flag && 1ll*primes[j]*mid<=n){
                    if(ans[primes[j]*mid]){
                        flag=true;
                    }
                    j++;
                }
            }

            if(flag){
                l=mid;
            }
            else{
                r=mid;
            }
        }
        
        bool flag=false;
        if(ans[r]){
            int j=0;
            while(!flag && 1ll*primes[j]*r<=n){
                if(ans[r*primes[j]]){
                    flag=true;
                }
                j++;
            }
        }
        if(flag){
            a[i]=r;
        }
        else{
            a[i]=l;
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