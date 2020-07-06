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

int f(string& s, string& t, int i,int j){
    int x=i,ans=0;
    while(x<=j){
        if(t[x-i]!=s[x]) ans++;
        x++;
    }   
    if(x-i<t.size()) ans+=(t.size()-x+i);
    return ans;
}

void solve(){
    string s,ss,t;
    cin>>ss>>t;
    for(int i=0;i<t.size();i++) s.pb('A');
    for(int i=0;i<ss.size();i++) s.pb(ss[i]);
    for(int i=0;i<t.size();i++) s.pb('A');
    int ans=t.size();
    for(int i=0;i<s.size();i++) ans=min(ans,f(s,t,i,min(i-1+t.size(),s.size()-1)));
    cout<<ans<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}