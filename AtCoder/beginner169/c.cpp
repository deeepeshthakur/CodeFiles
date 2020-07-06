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
    long long a;
    string b;
    cin>>a>>b;
    
    long long c=0,mul=100;
    for(int i=0;i<b.size();i++){
        if('0'<=b[i] && b[i]<='9'){
            c+=int(b[i]-'0')*mul;
            mul/=10;
        }
    }
    cout<<(a*c)/100<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}