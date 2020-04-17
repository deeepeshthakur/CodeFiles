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

void get_factors(int n,vector<bool>& primes, vector<vector<pair<int,int>>>& f){
    // vector<bool> primes(n+1,true);
    primes[0]=false;
    primes[1]=false;

    for(int i=0;i<=n;i++){
        if(primes[i]){
            f[i].pb({i,1});
            for(int j=2;i*j<=n;j++){
                primes[i*j]=false;
                int x=i,cnt=1;
                while((i*j)%x==0){
                    x*=i;
                    cnt++;
                }
                f[i*j].pb({i,cnt-1});
            }
        }
    }
}

void solve(vector<bool>& is_prime, vector<int>& primes, vector<vector<pair<int,int>>>& factors){
    int n,m;
    cin>>n>>m;
    vector<int> a(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(full(a));
    vector<int> gcd_seq(m+1,0);
    for(int i=0;i<n;i++){
        if(a[i]>1){
            int x=a[i];
            for(int j=0;j<factors[x].size();j++){
                gcd_seq[factors[x][j].first]=max(gcd_seq[factors[x][j].first],factors[x][j].second);
            }
        }
    }


    int ans=1,mx=1,tmp_gcd=1;

    for(int i=2;i<=m;i++){
        tmp_gcd=1;
        for(int j=0;j<factors[i].size();j++){
            int k=min(factors[i][j].second,gcd_seq[factors[i][j].first]);
            while(k>0){
                tmp_gcd*=factors[i][j].first;
                k--;
            }
        }
        if(i/tmp_gcd > mx){
            ans=i;
            mx=i/tmp_gcd;
        }
    }
    if(mx==1){
        ans=1;
    }
    cout<<ans<<"\n";
}   

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    vector<bool> isprimes(10001,true);
    vector<vector<pair<int,int>>> factors(10001);
    vector<int> primes;
    get_factors(10000,isprimes,factors);
    for(int i=0;i<isprimes.size();i++){
        if(isprimes[i]){
            primes.pb(i);
        }
    }
    int t;
    cin >> t;
    while(t--){
        solve(isprimes,primes,factors);
    }
    return 0;
}