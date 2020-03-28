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
    int n,k;
    cin>>n>>k;
    int sum=0;
    if(n>=k || n%2 == k%2){
        for(int i=1;i<k && sum <= n;i++){
            sum += (2*i-1);
        }
        if(sum<=n && (n-sum)%2==1 && n-sum>=(2*k-1)){
            cout<<"YES\n";
            return;
        }
    }

    cout<<"NO\n";
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