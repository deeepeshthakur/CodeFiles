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

void solve(int test_case){
    int n;
    long long b;
    cin >> n>>b;
    vector<int> a(n,0);
    for(int i=0;i<n;i++)
        cin>>a[i];
    
    sort(full(a));
    int ans=0;
    for(int i=0;i<n;i++){
        if(b>=a[i]){
            ans++;
            b-=a[i];
        }
    }
    
    cout<<"Case #"<<test_case<<": "<<ans<<"\n";
    
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        solve(i);
    }
    return 0;
}