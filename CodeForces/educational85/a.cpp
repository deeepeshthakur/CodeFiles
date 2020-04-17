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
    vector<int> p(n),c(n);
    for(int i=0;i<n;i++){
        cin>>p[i]>>c[i];
    }
    bool flag=true;
    for(int i=0;i<n;i++){
        int x=p[i],y=c[i];
        if(i>0){
            x-=p[i-1];
            y-=c[i-1];
        }
        if(!(x>=0 && y>=0 && x>=y)){
            flag=false;
        }
    }
    if(flag){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t;
    cin >> t;
    // t=1;
    while(t--){
        solve();
    }
    return 0;
}