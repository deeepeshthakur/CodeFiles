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
const long long MOD=1e9;

long long p(long long a){
    if(a%MOD==0) return MOD;
    return a%MOD;
}

long long rec(int &ind, string& str, long long e, long long w, long long n, long long s){
    if(ind>=str.size()) return 0ll;
    // long long ans=0;
    int tmp=0;long long sm=0;
    if(str[ind]>='A' && str[ind]<='Z'){
        tmp=ind;
        while(tmp<str.size() && str[tmp]>='A' && str[tmp]<='Z'){
            if(str[tmp]=='E') {sm+=e;sm=p(sm);}
            if(str[tmp]=='W') {sm+=w;sm=p(sm);}
            if(str[tmp]=='N') {sm+=n;sm=p(sm);}
            if(str[tmp]=='S') {sm+=s;sm=p(sm);}
            tmp++;
        }
        ind=tmp;
    }
    else{
        // cout<<"Here "<<ind<<" "<<str[ind]<<" ";
        long long mul=int(str[ind]-'0');
        tmp=ind+2;
        while(tmp<str.size() && str[tmp]!=')'){
            sm+=p(mul*rec(tmp,str,e,w,n,s));
            sm=p(sm);
        }
        ind=tmp;
        if(ind<str.size() && str[ind]==')'){
            ind++;
        }
        // cout<<ind<<" "<<(ind<str.size()?str[ind]:'*')<<"\n";
    }
    
    return p(sm);
}

void solve(int test_case){
    string s;cin>>s;
    int n=s.size(),tmp;
    long long x=1,y=1;
    for(tmp=0;tmp<s.size();){
        x+=rec(tmp,s,MOD+1,MOD-1,0ll,0ll);
        x=p(x);
    }

    for(tmp=0;tmp<s.size();){
        // cout<<tmp<<" ";
        y+=rec(tmp,s,0ll,0ll,MOD-1,MOD+1);
        y=p(y);
        // cout<<y<<"\n";
    }
    cout<<"Case #"<<test_case<<": "<<p(x)<<" "<<p(y)<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        solve(i);
    }
    return 0;
}