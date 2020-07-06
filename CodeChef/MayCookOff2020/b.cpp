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

bool tf(string& a, int x,int y){
    if(y-x+1<=20){
        int l=(y-x+1)/2;
        for(int i=x;i+l<=y;i++) if(a[i]!=a[i+l]) return false;
    }
    else{
        int l=(y-x+1)/2,ind;
        for(int i=0;i<10;i++){
            ind=x+(rand()%l);
            if(a[ind]!=a[ind+l]) return false;
        }
    }
    return true;
}

void solve(){
    string s;
    cin>>s;
    int ans=0;
    for(int i=2;i<s.size();i+=2){
        if(tf(s,0,i-1)&&tf(s,i,s.size()-1)) ans++;
    }
    cout<<ans<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    srand(time(0));
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}