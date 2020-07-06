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
    vector<int> a(2*n,0),b(2*n,0);
    for(int i=0;i<2*n;i++){
        cin>>a[i];
    }
    vector<pair<int,int>> ord(a.size(),{0,0});

    for(int i=20;i>=1;i--){
        int tmp=(1<<i);
        for(int j=0;j<a.size();j++) b[j]=(a[j]%tmp);
        if(tf(2*n,b,ord)){
            
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}