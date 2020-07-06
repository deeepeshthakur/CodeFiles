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
    string s;
    cin>>s;
    n=s.size();
    vector<int> dp(n,0);
    for(int i=0;i<n;i++) dp[i]=(s[i]=='+'?1:-1);
    long long init=0,curr=0,res=0;
    for(int i=0;i<n;i++){
        curr+=dp[i];
        if(curr<0){
            res+=(i+1);
            curr++;
            init++;
        }
    }
    cout<<res+n<<"\n";
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