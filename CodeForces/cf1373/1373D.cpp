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

long long f(vector<long long>& a){
    int n=a.size();
    // print_vec(a);
    long long max_so_far = 0, max_ending_here = 0; 

    for (int i = 0; i < n; i++) 
    { 
        max_ending_here = max_ending_here + a[i]; 
        if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here; 
  
        if (max_ending_here < 0) 
            max_ending_here = 0; 
    } 
    return max_so_far; 
}

void solve(){
    int n;
    cin>>n;
    vector<long long> a(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<long long> b,c;
    for(int i=0;i+1<n;i+=2){
        b.pb(-a[i]+a[i+1]);
    }
    for(int i=1;i+1<n;i+=2){
        c.pb(a[i]-a[i+1]);
    }
    long long ans=0;
    ans=max(ans,max(f(b),f(c)));
    for(int i=0;i<n;i+=2) ans+=a[i];
    cout<<ans<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}