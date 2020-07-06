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

void f1(string s){
    int n=s.size();
    int r=0,c=0;
    for(int i=1;i<s.size() && s[i]!='C';i++){
        r=10*r+int(s[i]-'0');
    }
    bool flag=false;
    for(int i=0;i<n;i++){
        if(!flag){
            flag=(s[i]=='C');
        }
        else{
            c=c*10+int(s[i]-'0');
        }
    }
    vector<char> v;
    while(c){
        if(c%26==0) v.pb('Z');
        else v.pb(c%26+'A'-1);

        c-=(c%26!=0?c%26:26);
        c/=26;
    }
    for(int i=v.size()-1;i>=0;i--) cout<<v[i];
    cout<<r<<"\n";
}

void f2(string s){
    int n=s.size(),r=0,c=0;
    for(int i=0;i<n;i++){
        if('0'<=s[i] && s[i]<='9'){
            r=r*10+int(s[i]-'0');
        }
        else{
            c=c*26+int(s[i]-'A'+1);
        }
    }
    cout<<"R"<<r<<"C"<<c<<"\n";
}

void solve(){
    string s;cin>>s;
    if(s[0]=='R' && '0'<=s[1] && s[1]<='9'){
        bool flag=true;
        for(int i=2;i<s.size();i++){
            if(s[i]=='C'){
                f1(s);
                return;
            }
        }
    }
    f2(s);
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