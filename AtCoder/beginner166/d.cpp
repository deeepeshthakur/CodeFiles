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
    long long x;cin>>x;
    long long a,b;
    for(long long i=-1000;i<=1000;i++){
        for(long long del=0;del<=1000;del++){
            long long lhs=(i+del)*(i+del)*(i+del)*(i+del)*(i+del)-i*i*i*i*i;
            if(lhs==x){
                a=del+i;
                b=i;
                del=2000;
                i=2000;
            }
        }
    }
    cout<<a<<" "<<b<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}