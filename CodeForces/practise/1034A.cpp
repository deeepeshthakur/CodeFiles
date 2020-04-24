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
    int n;cin>>n;
    vector<int> a(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    int gd=a[0];
    for(int i=0;i<n;i++) gd=__gcd(a[i],gd);
    for(int i=0;i<n;i++) a[i]/=gd;
    sort(full(a));
    if(a[n-1]==1){
        cout<<"-1\n";
        return;
    }
    vector<bool> is_primes(int(5e5)+1,true);is_primes[0]=is_primes[1]=false;
    vector<int> primes;
    for(int i=0;i<is_primes.size();i++){
        if(is_primes[i]){
            primes.pb(i);
            int j=i;
            while(1ll*j*i<is_primes.size()){
                is_primes[i*j]=false;
                j++;
            }
        }
    }
    int xx=primes.size()-1;
    vector<int> p2;
    for(int i=0;i<n;i++){
        if((i==0 || a[i]!=a[i-1])&&(a[i]>primes[xx])){
            int tmp=a[i];
            for(int j=0;j<=xx && 1ll*primes[j]*primes[xx]<=tmp;j++){
                while(tmp%primes[j]==0) tmp/=primes[j];
            }
            if(tmp!=a[i] && tmp>primes[xx]) p2.pb(tmp);
        }
    }

    map<int,int> ht;
    for(int i=0;i<n;i++) 
        if(i==0 || a[i]!=a[i-1]) ht.insert({a[i],1});
        else ht[a[i]]++;

    int ans=0;
    for(int i=p2.size()-1;i>=0;i--){
        int j=1,tmp=0;
        while(1ll*p2[i]*j<=a[n-1]){
            if(ht.find(p2[i]*j)!=ht.end()){
                tmp+=ht[p2[i]*j];
                if(ht.find(j)==ht.end()){
                    ht.insert({j,ht[p2[i]*j]});
                }
                else
                    ht[j]+=ht[p2[i]*j];
                j++;               
            }
        }
        ans=max(tmp,ans);
    }

    
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}