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
    string s;
    cin>>s;
    int r=0,g=0,b=0;
    for(int i=0;i<n;i++){
        if(s[i]=='R'){
            r++;
        }
        if(s[i]=='G'){
            g++;
        }
        if(s[i]=='B'){
            b++;
        }
    }
    long long ans=(1ll*r*g*b);
    long long ans1=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(2*i-j<n && s[i]!=s[j] && s[j]!=s[2*i-j] && s[i]!=s[2*i-j]){
                ans1++;
            }
        }
    }
    cout<<ans-ans1<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}