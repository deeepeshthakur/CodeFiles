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

int f(int x){
    int ans=0;
    for(int i=1;i<100;i++){
        if(x>=i){
            x-=i;
            ans++;
        }
    }
    return ans;
}

void solve(){
    long long n;
    cin>>n;
    vector<int> primes;
    vector<bool> p(int(1e6)+1,true);
    p[0]=p[1]=false;
    for(int i=0;i<p.size();i++){
        if(p[i]){
            primes.pb(i);
            int j=i;
            while(1ll*i*j<p.size()){
                p[i*j]=false;
                j++;
            }
        }
    }
    int ans=0;
    for(int i=0;i<primes.size();i++){
        if(n%primes[i]==0){
            int x=0;
            while(n%primes[i]==0){
                x++;
                n/=primes[i];
            }
            ans+=f(x);
        }
    }
    if(n!=1){
        ans+=1;
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