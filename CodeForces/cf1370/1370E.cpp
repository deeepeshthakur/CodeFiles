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

int f(int n, string s, string t){
    string ss="",tt="";
    for(int i=0;i<n;i++){
        if(s[i]!=t[i]){
            ss.pb(s[i]);
            tt.pb(t[i]);
        }
    }
    n=ss.size();
    for(int i=0;i<n;i++) ss.pb(ss[i]);
    int sl=0,sr=0;
    for(int i=0;i<n;i++){
        int j=i;
        for(;j+1<ss.size()&&ss[j+1]==ss[i];j++);
        if(sl<(j-i+1)) sl=j-i+1;
        i=j;
    }
    return sl;
}

void solve(){
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    int x=0;
    for(int i=0;i<n;i++){
        if(s[i]=='0') x++;
        if(t[i]=='0') x--;
    }
    if(x==0){
        int ans=f(n,s,t);
        cout<<ans<<"\n";
    }
    else{
        cout<<"-1\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}