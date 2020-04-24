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
    long long n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    for(int i=c-d;i<=c+d;i++){
        int x=(i/n),d=i-x*n;
        if(d>0){
            if(a-b<=x && x+1<=a+b){
                cout<<"Yes\n";
                return;
            }
        }
        else{
            if(a-b<=x && x<=a+b){
                cout<<"Yes\n";
                return;
            }
        }
    }
    cout<<"No\n";
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