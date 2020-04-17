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

vector<int> dp(int(5e6)+1,0);

void print_vec(vector<int>& a, int n=-1){
    n=(n==-1?a.size():n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<(i<n-1?" ":"\n");
}

void print_vec(vector<bool>& a, int n=-1){
    n=(n==-1?a.size():n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<(i<n-1?" ":"\n");
}

void print_vec(vector<long long>& a, int n=-1){
    n=(n==-1?a.size():n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<(i<n-1?" ":"\n");
}

void pre_calc(){
    // cout<<dp.size()<<"\n";
    vector<int> num_prime_fact(int(5e6)+1,0);
    vector<bool> is_prime(int(5e6)+1,true);
    is_prime[0]=false;
    is_prime[1]=false;  
    for(int i=0;i<is_prime.size();i++){
        if(is_prime[i]){
            num_prime_fact[i]=1;
            int j=2,x,mul;
            while(1ll*i*j<is_prime.size()){
                x=i*j;
                is_prime[i*j]=false;
                mul=0;
                while(x%i==0){
                    mul++;
                    x/=i;
                }
                num_prime_fact[i*j]+=mul;
                j++;                
            }
        }
    }
    for(int i=2;i<dp.size();i++){
        dp[i]=num_prime_fact[i]+dp[i-1];
    }
    // print_vec(num_prime_fact,100);
    // print_vec(is_prime,100);
    // print_vec(dp,100);
}

void solve(){
    int a,b;
    cin>>a>>b;
    cout<<dp[a]-dp[b]<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    pre_calc();
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}